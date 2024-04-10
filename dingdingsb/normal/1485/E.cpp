#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=2e5+10;
#define int long long
int t,n,a[N];vector<vector<int>>e,node;
vector<int>dep,fa,mx,mn,dp;
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	chkmx(mx[dep[u]],a[u]);
	chkmn(mn[dep[u]],a[u]);
	node[dep[u]].push_back(u);
	for(auto v:e[u])if(v!=fa[u])
		fa[v]=u,dfs1(v);
}
void work(){
	in::read(n);
//	* 
	e=vector<vector<int>>(n+1,vector<int>(0));
	node=vector<vector<int>>(n+1,vector<int>(0));
	dep=vector<int>(n+1);
	fa=vector<int>(n+1);
	dp=vector<int>(n+1,0);
	mx=vector<int>(n+1,-0x3f3f3f3f3f3f3f3f);
	mn=vector<int>(n+1,0x3f3f3f3f3f3f3f3f);
	for(int v,i=2;i<=n;i++)in::read(v),e[v].push_back(i),e[i].push_back(v);
	for(int i=2;i<=n;i++)in::read(a[i]);
	dfs1(1);
//	
//	dp
	vector<pair<int,int>>tmp;vector<int>pre,suf;
	for(int i=1;i<=n;i++){
		if(!node[i].size())break; 
		if(i!=1)
//			 
			for(auto u:node[i]){
				chkmx(dp[u],dp[fa[u]]+max(abs(a[u]-mx[i]),abs(a[u]-mn[i])));
//				
				int pos=lower_bound(tmp.begin(),tmp.end(),make_pair(a[u]+1,0ll))-tmp.begin();
//				tmp[pos]  second+a[u]-first
//				tmp[pos]  second+first-a[u]
//				ok
				if(pos!=0)chkmx(dp[u],pre[pos-1]+a[u]);
				if(pos!=tmp.size())chkmx(dp[u],suf[pos]-a[u]); 
				//printf("%d %d\n",u,dp[u]);
			}
		tmp.clear();int Mx,Mn;
		for(auto u:node[i]){
//			
			Mx=-0x3f3f3f3f3f3f3f3f;
			Mn=0x3f3f3f3f3f3f3f3f;
			for(auto v:e[u])if(v!=fa[u])
				chkmx(Mx,a[v]),chkmn(Mn,a[v]);
			tmp.push_back({Mx,dp[u]});
			if(Mn!=Mx)
			tmp.push_back({Mn,dp[u]});
		}
		if(!tmp.size())break;
		sort(tmp.begin(),tmp.end());pre.resize(tmp.size());suf.resize(tmp.size());
		pre[0]=tmp[0].second-tmp[0].first;for(int i=1;i<tmp.size();i++)pre[i]=max(pre[i-1],tmp[i].second-tmp[i].first);
		suf[tmp.size()-1]=tmp[tmp.size()-1].second+tmp[tmp.size()-1].first;for(int i=(int)(tmp.size())-2;i>=0;i--)suf[i]=max(suf[i+1],tmp[i].second+tmp[i].first);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		chkmx(ans,dp[i]);
	out::write(ans);
	out::putc('\n');
}
signed main(){
	in::read(t);
	while(t--)work();
	out::flush();
	return 0;
	//cout<<"fuck cccccccccccccccccf"
}