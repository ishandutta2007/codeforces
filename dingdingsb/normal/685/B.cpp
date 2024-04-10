 #pragma GCC optimize(3,"Ofast","inline")
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
const int N=300005;
int n,q,x,fa[N],rt[N],sz[N],mx[N];
vector<int>e[N];
void dfs(int u,int pre){
	sz[u]=1;
	for(auto v:e[u]){
		dfs(v,u);
		sz[u]+=sz[v];
		mx[u]=max(mx[u],sz[v]);
	}
	int id=u,me=mx[u];
	for(auto v:e[u]){
		int it=rt[v],pre=max(mx[it],sz[u]-sz[it]),p=it;
		while(fa[it]!=u){
			it=fa[it];
			int New=max(mx[it],sz[u]-sz[it]);
			if(New<pre)pre=New,p=it;else break;
		}
		if(me>pre)me=pre,id=p;
	}rt[u]=id;
}
signed main(){
	in::read(n,q);
	for(int i=2;i<=n;i++)
		in::read(fa[i]),e[fa[i]].push_back(i);
	dfs(1,0);
	while(q--)in::read(x),out::write(rt[x]),out::putc('\n');
	out::flush();
	return 0;
}