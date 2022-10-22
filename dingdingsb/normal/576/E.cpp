#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
		while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isdigit(c)&&!isalpha(c))c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
	void puts(char *s){int now=0;while(s[now]!='\0')putc(s[now++]);putc('\n');}
}
using namespace std;
const int N=2e6+10,M=51;
int n,m,k,q;
pair<int,int>e[N],qry[N],nowson[N];
int lstq[N],nxtime[N],col[N],nowcol[N],cnt;
unordered_map<int,int>id[M];
int f[N],c[N][2],sz[N],ti[N],mn[N];bool r[N];
#define lc (c[x][0])
#define rc (c[x][1])
#define get(x) (c[f[(x)]][1]==(x))
#define nroot(x) (c[f[(x)]][0]==(x)||c[f[(x)]][1]==(x))
void pushr(int x){swap(lc,rc);r[x]^=1;}
void pushup(int x){
	sz[x]=sz[lc]+(x<=m)+sz[rc];
	mn[x]=ti[mn[lc]]<ti[mn[rc]]?mn[lc]:mn[rc];
	if(x<=m)mn[x]=ti[mn[x]]<ti[x]?mn[x]:x;
}
void pushdown(int x){if(r[x]){if(lc)pushr(lc);if(rc)pushr(rc);r[x]=0;}}
void pushall(int x){if(nroot(x))pushall(f[x]);pushdown(x);}
void rotate(int x){
	int fa=f[x],ffa=f[fa],k=get(x),w=c[x][!k];
	if(nroot(fa))c[ffa][get(fa)]=x;c[x][!k]=fa;c[fa][k]=w;
	if(w)f[w]=fa;f[fa]=x;f[x]=ffa;pushup(fa);
}
void splay(int x){
	pushall(x);
	//
	while(nroot(x)){
		int fa=f[x];
		if(nroot(fa))
			rotate(get(x)==get(fa)?fa:x);
		rotate(x);
	}pushup(x);
}
void access(int x){
	for(int y=0;x;x=f[y=x])
		splay(x),rc=y,pushup(x);
}
void makeroot(int x){
	access(x);splay(x);pushr(x);
}
int findroot(int x){
	access(x);splay(x);
	while(lc)pushdown(x),x=lc;
	splay(x);return x;
}
void split(int x,int y){
	makeroot(x);access(y);splay(y);
}
void link(int x,int y){
	split(x,y);f[x]=y;
}
void linkedge(int E){
	nowson[E].first=id[nowcol[E]][e[E].first];
	nowson[E].second=id[nowcol[E]][e[E].second];
	link(nowson[E].first,E);
	link(E,nowson[E].second);
}
void cut(int x,int y){
	split(x,y);
	f[x]=c[y][0]=0;pushup(y);
}
void cutedge(int E){
	cut(nowson[E].first,E);
	cut(E,nowson[E].second);
	nowcol[E]=0;
}
signed main(){
	in::read(n,m,k,q);cnt=m;
	for(int i=1;i<=m;i++)in::read(e[i].first,e[i].second);
	for(int i=1;i<=q;i++)in::read(qry[i].first,qry[i].second);
	for(int i=1;i<=m;i++)lstq[i]=q+1;
	for(int i=q;i;i--)nxtime[i]=lstq[qry[i].first],lstq[qry[i].first]=i;
	ti[0]=1e9;
	for(int i=1;i<=q;i++){
		int x=qry[i].first,y=qry[i].second;
		if(nowcol[x])cutedge(x);
		ti[x]=nxtime[i];
		bool flag=false;
		if(id[y].find(e[x].first)==id[y].end())
			flag=1,id[y][e[x].first]=++cnt;
		if(id[y].find(e[x].second)==id[y].end())
			flag=1,id[y][e[x].second]=++cnt;
		int u=id[y][e[x].first],v=id[y][e[x].second];
		if(!flag){
			if(findroot(u)!=findroot(v))flag=1;
			else{
				split(u,v);
				flag|=sz[v]&1;
			}
		}
		if(flag){
			out::puts("YES");
			col[x]=y;
			if(findroot(u)==findroot(v)){
				split(u,v);
				int now=mn[v];
				if(ti[x]<=ti[now])continue;
				cutedge(now);
				nowcol[x]=y;
				linkedge(x);
			}else nowcol[x]=y,linkedge(x);
		}
		else{
			out::puts("NO");
			if(col[x]){
				u=id[col[x]][e[x].first];
				v=id[col[x]][e[x].second];
				if(findroot(u)==findroot(v)){
					split(u,v);
					int now=mn[v];
					if(ti[x]<=ti[now])continue;
					cutedge(now);
					nowcol[x]=col[x];
					linkedge(x);
				}else nowcol[x]=col[x],linkedge(x);
			}
		}
	}
	out::flush();
}