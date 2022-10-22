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
#define int long long
const int N=2e5+100;
int n,a[N];vector<int>e[N];
#define INF 0x3f3f3f3f3f3f3f3f
int leaf[N],f[N];
int dfs(int u,int fa){
	int mx=-INF,sum=0;leaf[u]=0;
	for(auto v:e[u])
		dfs(v,u),
		mx=max(mx,f[v]),
		a[u]+=a[v],
		leaf[u]+=leaf[v];
	if(mx==-INF){
		leaf[u]=1;
		return f[u]=a[u];
	}// 
	if(leaf[u]*mx>=a[u]){
		//
		return f[u]=mx; 
	}
	return f[u]=(a[u]+leaf[u]-1)/leaf[u];
}
signed main(){
	in::read(n);
	for(int i=2,p;i<=n;i++)
		in::read(p),e[p].push_back(i);
	for(int i=1;i<=n;i++)in::read(a[i]);
	out::write(dfs(1,0));
	out::flush();
	return 0;
}