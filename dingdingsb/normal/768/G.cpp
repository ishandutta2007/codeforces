//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
namespace In{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace Out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int maxn=1e6+7;
const int inf=0x3f3f3f3f;
int n,m,rt;
vector<int>e[maxn];
template<typename T>
struct my___sjy__xzy_set{
	multiset<T>s;
	void operator +=(T x){s.insert(x);}
	void operator -=(T x){s.erase(s.find(x));}
	inline T find(T x){
		auto it=s.lower_bound(x);
		return it==s.end()?inf:(*it);
	}
	T bound(int l,int x,int y,int ex){
		int r=x;
		while(l<=r){
			int mid=l+r>>1;
			if(find(x+ex-mid)<=-y+ex+mid)r=mid-1;
			else l=mid+1;
		}return min(l,x);
	}
};
my___sjy__xzy_set<int>anc,son,out;
int res[maxn],sz[maxn];
int getsz(int u){
	sz[u]=1;
	for(auto v:e[u])
		sz[u]+=getsz(v);
	out+=sz[u];
	return sz[u];
}
inline void ins(int u){
	son+=sz[u],out-=sz[u];
	for(auto v:e[u])ins(v);
}
inline void del(int u){
	son-=sz[u],out+=sz[u];
	for(auto v:e[u])del(v);
}
void dfs(int u){
	out-=sz[u];
	anc+=sz[u];//uu
	int son1=0,son2=0,mn=inf;
	//
	for(auto v:e[u]){
		mn=min(mn,sz[v]);
		if(sz[v]>sz[son1])son2=son1,son1=v;
		else if(sz[v]>sz[son2])son2=v;
	} 
	for(auto v:e[u])
		if(v!=son1)
			dfs(v),del(v);
			//
	if(son1)dfs(son1);
	if(u!=rt)mn=min(mn,n-sz[u]);
	if(sz[son1]>=n-sz[u]){
		//son1
		res[u]=min(res[u],son.bound(max(sz[son2],n-sz[u]),sz[son1],mn,0)); 
	} 
	anc-=sz[u];son+=sz[u];
	//sonu
	for(auto v:e[u])
		if(v!=son1)ins(v);
	if(n-sz[u]>sz[son1]){
		//
		res[u]=min(res[u],anc.bound(sz[son1],n-sz[u],mn,sz[u]));
		res[u]=min(res[u],out.bound(sz[son1],n-sz[u],mn,0)); 
	} 
}
signed main(){
	In::read(n);
	for(int i=1,u,v;i<=n;i++){
		In::read(u,v);
		if(!u||!v)rt=u^v;
		else e[u].push_back(v);
	} 
	sz[0]=-inf;memset(res,inf,sizeof res);
	getsz(rt);
	dfs(rt);
	for(int i=1;i<=n;i++)
		Out::write(res[i]),Out::putc('\n');
	Out::flush();
	return 0;
}