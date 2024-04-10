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
	void write(int x) {
		static char buf[15];
		static int len=-1;
		if(x>=0){
			do{
    			buf[++len] = x % 10 + 48, x /= 10;
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
const int maxn=2e5+10;
int n,a,b,rt;
int head[maxn];
struct node{
	int v;
	int nxt;
}e[maxn<<1];
int cnt=0;
inline void add(int u,int v){
	cnt++;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
#define ERR -1
int dfs(int x,int fa){
	set<int>s;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].v==fa)continue;
		int tmp=dfs(e[i].v,x);
		if(tmp==ERR)return ERR;
		s.insert(tmp+1);
	}
	if(s.size()==0)return 0;
	if(s.size()==1)return *s.begin();
	if(s.size()==2&&fa==-1)return *s.begin()+*s.rbegin();
	rt=x;
	return ERR;
}
signed main(){
	in::read(n);
	for(int i=1;i<n;i++)
		in::read(a,b),add(a,b),add(b,a);
	int ans=dfs(1,-1);
	if(ans==ERR&&rt)ans=dfs(rt,-1);
	while((ans&1)==0)
		ans>>=1;
	out::write(ans);
	out::flush();
	return 0;
}