#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=2e5+100;
struct Graph{
	struct node{int v,nxt;
		node(int _v=0,int _n=0){v=_v,nxt=_n;}
	}e[maxn<<1];
	int head[maxn],cnt;
	void add(int u,int v){e[++cnt]=node(v,head[u]);head[u]=cnt;}
	#define For(G,x) for(int ___=(G).head[x];___;___=(G).e[___].nxt)
	#define v(G) (G).e[___].v
}G;
long long n,a[maxn],b[maxn],c[maxn],bb=0,cc=0,u,v;
long long fa[maxn],s1[maxn],s2[maxn];//s1 1->0  s2  0->1
long long ans=0;
void dfs(int x,int Fa){
	fa[x]=Fa;if(fa[x])a[x]=min(a[x],a[fa[x]]);
	For(G,x)if(v(G)!=Fa)dfs(v(G),x),s1[x]+=s1[v(G)],s2[x]+=s2[v(G)];
	if(b[x]==1&&c[x]==0)s1[x]++;
	if(b[x]==0&&c[x]==1)s2[x]++;
	int mn=min(s1[x],s2[x]);
	s1[x]-=mn,s2[x]-=mn;
	ans+=2*mn*a[x];
}

signed main(){
	//freopen("edit.in","r",stdin);
	//freopen("edit.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i],b[i],c[i]),bb+=b[i],cc+=c[i];
	for(int i=1;i<n;i++)
		read(u,v),G.add(u,v),G.add(v,u);
	if(bb!=cc)write(-1),exit(0);
	dfs(1,0);
	write(ans);
}