#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 77,inf=0x3f3f3f3f;
int dis[(1<<17|3)*202],n,m,a,b,f[N],bel[N],num,bh[N],sz[N],A[666],B[666],C[666];
bool vis[(1<<17|3)*202];
vector<Pii>e[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline int dy(int x, int y){//S,u
	return x*n+y;
}
inline Pii decode(int s){
	if(s%n)return Pii(s/n,s%n);
	return Pii(s/n-1,n);
}
inline int getbit(int u){return !bel[u]?0:1<<bel[u]-1;}
//decode:(c/n,c%n)
struct Que{
	int q[(1<<17|3)*202],f,r;
	inline void push(int x){
		q[r++]=x;
	}
	inline void pop(){
		f++;
	}
	inline int front(){
		return f!=r?q[f]:inf;
	}
	inline bool empty(){return f==r;}
}q1,q2;
int main() {
	read(n);read(m);read(a);read(b);
	rep(i,1,n)f[i]=i;
	rep(i,1,m){
		int u,v,x;read(u);read(v);read(x);A[i]=u;B[i]=v;C[i]=x;
		if(x==a){u=find(u);v=find(v);f[u]=v;}
	}
	rep(i,1,n)sz[find(i)]++;
	rep(i,1,n)if(find(i)==i&&sz[i]>=4)bh[i]=++num;
	rep(i,1,n)bel[i]=bh[find(i)];
	rep(i,1,m){
		int u=A[i],v=B[i],x=C[i];
		if(!(x==b&&find(u)==find(v))){
			e[u].pb(Pii(v,x));e[v].pb(Pii(u,x));
		}
	}
//	rep(i,1,n)printf("%d:%d\n",i,bel[i]);
	memset(dis,inf,sizeof(dis));
	int ori=dy(getbit(1),1);dis[ori]=0;q1.push(ori);
	while(!q1.empty()||!q2.empty()){
		int S=0;if(!q1.empty()&&dis[q1.front()]<dis[S])S=q1.front();
		if(!q2.empty()&&dis[q2.front()]<dis[S])S=q2.front();
		if(S==q1.front())q1.pop();else q2.pop();
	//	printf("s=%d\n",S);
		if(vis[S])continue;else vis[S]=1;
		Pii tmp=decode(S);int x=tmp.fi,u=tmp.se;
		rep(i,0,SZ(e[u])-1){
			int y=x;bool ok=1;
			if(e[u][i].se==b){
				if(!(getbit(e[u][i].fi)&x)){
					y|=getbit(e[u][i].fi);int T=dy(y,e[u][i].fi);//S-->T
					if(dis[T]>dis[S]+e[u][i].se){
						dis[T]=dis[S]+e[u][i].se;q2.push(T);
					}
				}
			}
			else{
				int T=dy(x,e[u][i].fi);
				if(dis[T]>dis[S]+e[u][i].se){
					dis[T]=dis[S]+e[u][i].se;q1.push(T);
				}
			}
		}
	}
	rep(i,1,n){
		int res=inf;
		rep(j,0,(1<<num)-1)umin(res,dis[dy(j,i)]);
		printf("%d ",res);
	}
	return 0;
}