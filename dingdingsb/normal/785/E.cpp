#include<bits/stdc++.h>
//#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
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
const int N=3e5+10;
int n,m,S,a[N];vector<int>v[N];
#define id(x) ((x-1)/S+1)
void upd(int l,int r){
	if(id(l)!=id(r)){
		v[id(l)].erase(lower_bound(v[id(l)].begin(),v[id(l)].end(),a[l]));
		v[id(r)].erase(lower_bound(v[id(r)].begin(),v[id(r)].end(),a[r]));
		v[id(l)].insert(lower_bound(v[id(l)].begin(),v[id(l)].end(),a[r]),a[r]);
		v[id(r)].insert(lower_bound(v[id(r)].begin(),v[id(r)].end(),a[l]),a[l]);
	}swap(a[l],a[r]);
}
int qry(int l,int r,int val){
	if(l>r)return 0;
	int cnt=0;
	if(id(l)==id(r)){
		for(int i=l;i<=r;i++)cnt+=a[i]<val;
		return cnt;
	}
	for(int i=l;i<=id(l)*S;i++)cnt+=a[i]<val;
	for(int i=(id(r)-1)*S+1;i<=r;i++)cnt+=a[i]<val;
	for(int i=id(l)+1;i<=id(r)-1;i++)cnt+=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
	return cnt;
}
signed main(){
	in::read(n,m);S=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=i,v[id(i)].push_back(i);
	long long ans=0;
	while(m--){
		int l,r;in::read(l,r);
		if(l>r)swap(l,r);
		if(l==r){
			out::write(ans);
			out::putc('\n');
			continue;
		}
		ans+=2*(qry(l+1,r-1,a[r])-qry(l+1,r-1,a[l]));
		if(a[l]<a[r])ans++;else ans--;upd(l,r);
		out::write(ans);
		out::putc('\n');
	}
	out::flush();
	return 0;
}