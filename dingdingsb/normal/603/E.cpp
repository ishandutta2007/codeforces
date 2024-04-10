// Problem: CF603E Pastoral Oddities
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF603E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=4e5+10,M=3e5+10;
int n,m,cnt;
//---lct
int c[N][2];int v[N];
int f[N];bool r[N];
pair<int,int>mx[N];
int s[N],d[N];
#define lc c[x][0]
#define rc c[x][1]
#define get(x) (c[f[x]][1]==x)
#define nroot(x) (c[f[x]][0]==x||c[f[x]][1]==x)
void pushup(int x){
	mx[x]={v[x],x};
	mx[x]=max(mx[x],mx[lc]);
	mx[x]=max(mx[x],mx[rc]);
	s[x]=s[lc]+s[rc]+d[x]+(x<=n);
}
void pushr(int x){
	r[x]^=1;
	swap(lc,rc);
}
void pushdown(int x){
	if(r[x]){
		pushr(lc);pushr(rc);
		r[x]=0;
	}
}
void rotate(int x){
	int fa=f[x],ffa=f[fa],k=get(x),w=c[x][!k];
	if(nroot(fa))c[ffa][get(fa)]=x;c[x][!k]=fa;c[fa][k]=w;
	if(w)f[w]=fa;f[fa]=x;f[x]=ffa;pushup(fa);pushup(x);
}
void pushall(int x){
	if(nroot(x))pushall(f[x]);
	pushdown(x);
}
void splay(int x){
	pushall(x);
	while(nroot(x)){
		int fa=f[x];
		if(nroot(fa))
			rotate(get(x)!=get(fa)?x:fa);
		rotate(x);
	}pushup(x);
}
void access(int x){
	for(int y=0;x;x=f[y=x])
		splay(x),d[x]+=s[rc],
		d[x]-=s[rc=y],pushup(x);
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
	makeroot(x);access(y);splay(y);
	cnt-=s[x]&1;cnt-=s[y]&1;
	d[f[x]=y]+=s[x];pushup(y);cnt+=s[y]&1;
}
void cut(int x,int y){
	split(x,y);cnt-=s[y]&1;
	f[x]=c[y][0]=0;pushup(y);
	cnt+=s[x]&1;cnt+=s[y]&1;
}
priority_queue<pair<int,int>>q;
int x[N],y[N],z[N];bool del[N];
signed main(){
	read(n,m);cnt=n;
	for(int i=1;i<=m;i++){
		int u,v,w;read(u,v,w);x[i]=u,y[i]=v,z[i]=w;
		bool flag=true;
		if(findroot(u)==findroot(v)){
			split(u,v);
			auto tmp=mx[v];
			if(tmp.first>w){
				cut(x[tmp.second-n],tmp.second);
				cut(y[tmp.second-n],tmp.second);
				del[tmp.second-n]=1;
			}else flag=0;
		}
		if(flag){
			s[i+n]=1;::v[i+n]=w;
			link(u,i+n);
			link(v,i+n);
			q.push({w,i});
		}
		if(cnt)puts("-1");
		else{
			while(q.size()){
				int o=q.top().second;
				q.pop();
				if(del[o])continue;
				cut(x[o],o+n);
				cut(y[o],o+n);
				if(cnt){
					link(x[o],o+n);
					link(y[o],o+n);
					q.push({z[o],o});
					write(z[o]);putchar('\n');
					break;
				}
			}
		}
	}
}