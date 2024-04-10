#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
const int INF=1e9;

int n,m;
struct E{
	int t,n,v,c;
}e[5010];
int cnt=1,last[55];
inline void addedge(int x,int y,int c){
	e[++cnt]=(E){y,last[x],1,c},last[x]=cnt;
	e[++cnt]=(E){x,last[y],0,-c},last[y]=cnt;
}
int dis[55],h[55],pid[55];
bool dijkstra(){
	static P hp[2510]; int top;
	rep(i,1,n) dis[i]=INF;
	auto cmp=[&](const P &x,const P &y){return y<x;};  //caution cmp
	dis[1]=0; hp[top=1]=P(dis[1],1);
	while (top){
		const P c=hp[1]; hp[1]=hp[top--];
		pop_heap(hp+1,hp+top+1,cmp);
		if (dis[c.se]^c.fi) continue;
		int u=c.se,v;
		for (int i=last[u];i;i=e[i].n)
			if (v=e[i].t,e[i].v&&dis[u]+e[i].c+h[u]-h[v]<dis[v]){
				dis[v]=dis[u]+e[i].c+h[u]-h[v]; pid[v]=i;
				hp[++top]=P(dis[v],v); push_heap(hp+1,hp+top+1,cmp);
			}
	}
	return dis[n]!=INF;
}
vector<int> mcmf(){
	vector<int> S;
	while (dijkstra()){
		S.pb(dis[n]+h[n]);
		for (int i=n;i^1;i=e[pid[i]^1].t) e[pid[i]].v--,e[pid[i]^1].v++;
		rep(i,1,n) if (dis[i]^INF) h[i]+=dis[i];
	}
	return S;
}
void solve(){
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	auto S=mcmf();
	int q=read();
	while (q--){
		int x=read();
		double ans=1e18;
		int flw=0; double cst=0.0;
		for (const int &e: S){
			++flw,cst+=e;
			ans=min(ans,(cst+x)/flw);
		}
		printf("%.10lf\n",ans);
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}