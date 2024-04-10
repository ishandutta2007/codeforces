// #pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=2e5+1000;
struct node{int v,nxt;}e[maxn<<1];
int cnt=0,head[maxn];
void add(int u,int v){e[++cnt]=(node){v,head[u]};head[u]=cnt;}
int dis[maxn],fath[maxn],maxp;
bool flag[maxn];// 
int n,u,v;long long sum; 
struct nnn{int a,b,c;nnn(int A=0,int B=0,int C=0){a=A,b=B,c=C;}};
vector<nnn>ans;
queue<nnn>q;
int st,ed;
#define v e[i].v
void dfs1(int u,int fa){
	//
	//printf("%d %d\n",u,fa); 
	if(dis[u]>dis[maxp])maxp=u;fath[u]=fa; 
	for(int i=head[u];i;i=e[i].nxt){
		if(v==fa)continue;
		dis[v]=dis[u]+1;dfs1(v,u);
	}
}
void dfs2(int u){
	q.push(nnn(u,dis[u],dis[ed]-dis[u]));
	for(int i=head[u];i;i=e[i].nxt)
	if(flag[v]&&fath[u]!=v)dfs2(v);
}
#undef v
#define mp make_pair
#define pb push_back
signed main(){
	in::read(n);
	for(int i=1;i<n;i++)in::read(u,v),add(u,v),add(v,u);
	dis[maxp=0]=0,dfs1(1,-1);
	st=maxp;// 
	dis[st]=dis[maxp=0]=0,dfs1(st,-1);
	ed=maxp;//
	int _tmp=maxp;
	while(_tmp!=st)flag[_tmp]=true,_tmp=fath[_tmp];
	flag[st]=true;
	dfs2(st);
	while(!q.empty()){
		#define v e[i].v
		nnn tmp=q.front();q.pop();
		//printf("%d %d %d\n",tmp.a,tmp.b,tmp.c);
		if(flag[tmp.a])sum+=tmp.b,ans.pb(nnn(tmp.a,st,tmp.a));
		else {
			if(tmp.b>tmp.c)sum+=tmp.b,ans.pb(nnn(tmp.a,st,tmp.a));
			else 		   sum+=tmp.c,ans.pb(nnn(tmp.a,ed,tmp.a));
		} 
		for(int i=head[tmp.a];i;i=e[i].nxt){
			if(v==fath[tmp.a]||flag[v])continue;
			else	   q.push(nnn(v,tmp.b+1,tmp.c+1));
		}
		#undef v
	}
	out::write(sum);out::putc('\n');
	for(int i=ans.size()-1;i>=0;i--)if(ans[i].c!=st)
		out::write(ans[i].a),out::putc(' '),
		out::write(ans[i].b),out::putc(' '),
		out::write(ans[i].c),out::putc('\n'); 
	out::flush();
	return 0;
}