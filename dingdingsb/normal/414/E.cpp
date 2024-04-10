#include<bits/stdc++.h>
//#define faster
namespace fin{
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
namespace fout{
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
int n,m,in[N],out[N],id[N],dep[N],cnt;
vector<int>e[N];int root;
void dfs(int u,int dep){
	in[u]=++cnt,id[cnt]=u,::dep[cnt]=dep;
	for(auto v:e[u])dfs(v,dep+1);
	out[u]=++cnt,id[cnt]=u,::dep[cnt]=dep;
}
int f[N],ch[N][2],mn[N],mx[N],tag[N],sz[N];
#define min3(a,b,c) min((a),min(b,c))
#define max3(a,b,c) max((a),max(b,c))
void pushup(int x){
	int l=ch[x][0],r=ch[x][1];
	sz[x]=sz[l]+1+sz[r];
	mx[x]=max3(mx[l],dep[x],mx[r]);
	mn[x]=min3(mn[l],dep[x],mn[r]);
}
void add(int x,int val){
	mn[x]+=val,mx[x]+=val,tag[x]+=val,dep[x]+=val;
}
void pushdown(int x){
	int l=ch[x][0],r=ch[x][1];
	if(tag[x]){
		if(l)add(l,tag[x]);
		if(r)add(r,tag[x]);
	}tag[x]=0;
}
#define get(x) (ch[f[(x)]][1]==(x))
#define connect(x,y,p) {if(x)f[(x)]=(y);if(y)ch[(y)][(p)]=(x);}
void rotate(int x){
	int fa=f[x],ffa=f[fa],p1=get(x),p2=get(fa);
	connect(ch[x][p1^1],fa,p1);
	connect(fa,x,p1^1);
	connect(x,ffa,p2);
	pushup(fa);pushup(x);
}
void splay(int x,int goal=0){
	stack<int>q;q.push(x);
	for(int fa=x;f[fa]!=goal;fa=f[fa])q.push(f[fa]);
	while(q.size())pushdown(q.top()),q.pop();
	for(int fa;(fa=f[x])!=goal;rotate(x))
		if(f[fa]!=goal)rotate(get(x)==get(fa)?fa:x);
	if(!goal)root=x;
}
#define mid (l+r>>1)
int build(int l,int r){
	if(l<mid)ch[mid][0]=build(l,mid-1),f[ch[mid][0]]=mid;
	if(mid<r)ch[mid][1]=build(mid+1,r),f[ch[mid][1]]=mid;
	pushup(mid);return mid;
}
int findk(int x,int k){
	int l=ch[x][0],r=ch[x][1];pushdown(x);
	if(mn[r]<=k&&k<=mx[r])return findk(r,k);
	else if(dep[x]==k){splay(x);return id[x];}
	else return findk(l,k);
}
int split(int l,int r){
	splay(l);splay(r,l);return ch[r][0];
}
int getpre(int x){
	splay(x);x=ch[x][0];
	while(ch[x][1])x=ch[x][1];
	splay(x);return x;
}
int getsuf(int x){
	splay(x);x=ch[x][1];
	while(ch[x][0])x=ch[x][0];
	splay(x);return x;
}
int del(int l,int r){
	int L=getpre(l),R=getsuf(r);
	int x=split(L,R),y=f[x];
	ch[y][0]=f[x]=0;pushup(y);pushup(f[y]);
	return x;
}
signed main(){
	fin::read(n,m);
	for(int i=1,u,v;i<=n;i++){
		fin::read(u);
		for(int j=1;j<=u;j++)fin::read(v),e[i].push_back(v);
	}
	mn[0]=0x3f3f3f3f;
	dfs(1,0);build(1,cnt);
	while(m--){
		int op,u,v,k;
		fin::read(op);
		if(op==1){
			fin::read(u,v);
			splay(in[u]);int rku=sz[ch[in[u]][0]]+1,res=dep[in[u]];
			splay(in[v]);int rkv=sz[ch[in[v]][0]]+1;res+=dep[in[v]];
			if(rku>rkv)swap(u,v);u=split(in[u],out[v]);res-=(mn[u]-1)*2;
			fout::write(res);fout::putc('\n');
		}else if(op==2){
			fin::read(u,v);int val=v-1;
			splay(in[u]);v=findk(ch[in[u]][0],dep[in[u]]-v);
			u=del(in[u],out[u]);add(u,-val);
			int rt=getpre(out[v]);splay(rt);
			splay(out[v],rt);
			connect(u,out[v],0);
			pushup(out[v]),pushup(rt);
		}else{
			fin::read(k);
			splay(1);
			fout::write(findk(1,k));fout::putc('\n');
		}
	}
	fout::flush();
	return 0;
}