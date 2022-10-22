 //#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
	}
	template <typename T>inline void read(T& t){
	    t=0;int f=0;char ch=getc();
	    while (!isdigit(ch)){
	        if(ch=='-')f = 1;
	        ch=getc();
	    }
	    while(isdigit(ch)){
   	    	t=t*10+ch-48;
   	    	ch = getc();
   		}
		if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){
	    read(t);read(args...);
	}
}
namespace out{
	char buffer[1<<21];
	int p1=-1;
	const int p2 = (1<<21)-1;
	inline void flush() {
		fwrite(buffer,1,p1+1,stdout),
		p1=-1;
	}
	inline void putc(const char &x) {
		if(p1==p2)flush();
		buffer[++p1]=x;
	}
	template <typename T>void write(T x) {
		static char buf[15];
		static int len=-1;
		if(x>=0){
			do{
    			buf[++len]=x%10+48,x/=10;
    		}while (x);
		}else{
    		putc('-');
			do {
    			buf[++len]=-(x%10)+48,x/=10;
			}while(x);
		}
		while (len>=0)
			putc(buf[len]),--len;
	}
}
using namespace std;
#define int long long
int t,n,m,u,v;const int maxn=1e5+10;
vector<int>e[maxn];
#define pb push_back
int sz[maxn],fa[maxn];
vector<long long>val,pri;
const long long mod=1e9+7;
void dfs(int u){
	sz[u]=1;
	for(auto v:e[u])
		if(v!=fa[u]){
			fa[v]=u;
			dfs(v);
			sz[u]+=sz[v];
		}
	if(u!=1)val.pb(sz[u]*(n-sz[u]));
}bool cmp(int a,int b){
	return a>b;
}
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		val.clear();pri.clear();
		for(int i=1;i<=n;i++)
			e[i].clear(),sz[i]=0;
		for(int i=1;i<n;i++)
			in::read(u,v),e[u].pb(v),e[v].pb(u);
		fa[1]=0;dfs(1);
		sort(val.begin(),val.end(),cmp);
		in::read(m);
		for(int i=1;i<=m;i++){
			int a;in::read(a);
			pri.pb(a);
		}sort(pri.begin(),pri.end(),cmp);
		long long ans=0;
		if(m<=n-1){
			//
			for(int i=0;i<m;i++){
				val[i]*=pri[i];
				val[i]%=mod;
			} 
		}else{
			//
			while(pri.size()>=n){
				val[0]*=pri[0];val[0]%=mod;
				pri.erase(pri.begin());
			} 
			for(int i=0;i<pri.size();i++){
				val[i]*=pri[i];
				val[i]%=mod;
			} 
		}
		for(auto v:val)
			ans+=v,ans%=mod;
		out::write(ans);
		out::putc('\n');
	}out::flush();
}