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
const int N=3e5+10;
int root,minc;
int val[N],id[N],f[N],ch[N][2],tag[N],ans[N],num[N];queue<int>q;
void add(int u,int x,int y){tag[u]+=x,val[u]+=x,ans[u]+=y,num[id[u]]+=y;}
void pushdown(int x){
	int l=ch[x][0],r=ch[x][1];
	if(tag[x]!=0){
		if(l)add(l,tag[x],ans[x]);
		if(r)add(r,tag[x],ans[x]);
		tag[x]=ans[x]=0;
	}
}
#define get(x) (x==ch[f[x]][1])
#define connect(x,y,p) {if(x)::f[x]=y;if(y)ch[y][p]=x;}
void rotate(int x){
	int fa=f[x],ffa=f[fa],p1=get(x),p2=get(fa);
	connect(ch[x][p1^1],fa,p1);
	connect(fa,x,p1^1);
	connect(x,ffa,p2);
}
inline void splay(int x,int to){
	pushdown(x);
    for(int fa;(fa=f[x])!=to;rotate(x))
		if(f[fa]!=to)rotate(get(x)==get(fa)?fa:x);
	if(!to)root=x;
}
void ins(int x,int id){
	int u=root,f=0;
	while(u)pushdown(u),f=u,u=ch[u][x>val[u]];
	u=q.front();q.pop();
	val[u]=x,::id[u]=id;
	ch[u][0]=ch[u][1]=::f[u]=tag[u]=ans[u]=0;
	if(f)connect(u,f,x>val[f]);
	splay(u,0);
}
int pre(int x){
	int u=root,res=0;
	while(u)pushdown(u),val[u]<x&&(res=u),u=ch[u][val[u]<x];
	return res;
}
int nxt(int x){
	int u=root,res=0;
	while(u)pushdown(u),val[u]>x&&(res=u),u=ch[u][val[u]<=x];
	return res;
}
void upd(int u,int x){// 
	if(!u)return;
	pushdown(u);
	upd(ch[u][0],x);
	upd(ch[u][1],x);
	q.push(u);
	num[id[u]]++;
	if(val[u]-x>=minc)ins(val[u]-x,id[u]);
}
void down(int u){// 
	if(!u)return;
	pushdown(u);
	down(ch[u][0]);down(ch[u][1]);
}
int n,m;
struct node{
	int c,q;
	bool operator<(const node b)const{
	if(q!=b.q)return q>b.q;return c<b.c;}
}a[N];
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++)in::read(a[i].c,a[i].q),minc=min(minc,a[i].c);
	sort(a+1,a+1+n);in::read(m);
	for(int i=1;i<=m+10;i++)q.push(i);
	for(int i=1,x;i<=m;i++)in::read(x),ins(x,i);
	ins(-0x3f3f3f3f,0);//
	for(int i=1;i<=n;i++){
		int u,v,k;
		u=pre(a[i].c);splay(u,0);
		v=nxt(a[i].c*2-1);
		if(v){
			splay(v,u);
			k=ch[v][0];ch[v][0]=0;
			add(v,-a[i].c,1);
			upd(k,a[i].c);
		}else k=ch[u][1],ch[u][1]=0,upd(k,a[i].c);
	} 
	down(root);
	for(int i=1;i<=m;i++)
		out::write(num[i]),out::putc(' ');
	out::flush();
	return 0;
}