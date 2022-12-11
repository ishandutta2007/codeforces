#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
const int INF=1e9;

int n,m;

struct E{
	int t,n,v,c;
}e[1<<10];
int cnt=1,last[110],S,T;
inline void addedge(int x,int y,int v,int c){
	e[++cnt]=(E){y,last[x],v,c},last[x]=cnt;
	e[++cnt]=(E){x,last[y],0,-c},last[y]=cnt;
}

int dis[110],h[110],pid[110];

bool dijkstra(){
	static P hp[110]; int top;
	rep(i,1,T) dis[i]=INF; dis[S]=0;
	hp[top=1]=P(dis[S],S);
	const auto cmp=[&](const P &x,const P &y){return x>y;};
	while (top){
		const P x=hp[1];
		hp[1]=hp[top--];
		pop_heap(hp+1,hp+top+1,cmp);
		if (dis[x.se]^x.fi) continue;
		int u=x.se,v;
		for (int i=last[u];i;i=e[i].n)
			if (v=e[i].t,e[i].v&&
				dis[u]+h[u]-h[v]+e[i].c<dis[v]){
				dis[v]=dis[u]+h[u]-h[v]+e[i].c;
				pid[v]=i;
				hp[++top]=P(dis[v],v);
				push_heap(hp+1,hp+top+1,cmp);
			}
	}
	return dis[T]^INF;
}

int mcmf(){
	int z=0;
	while (dijkstra()){
		int f=INF;
		for (int i=T;i^S;i=e[pid[i]^1].t) f=min(f,e[pid[i]].v);
		z+=f*(dis[T]+h[T]);
		for (int i=T;i^S;i=e[pid[i]^1].t) e[pid[i]].v-=f,e[pid[i]^1].v+=f;
		rep(i,1,T) if (dis[i]^INF) h[i]+=dis[i];
	}
	//printf("mcmf %d\n",z);
	return z;
}

void solve(){
	static int d[110];
	n=read(),m=read();
	int ans=0;
	rep(i,1,m){
		int u=read(),v=read(),f=read(),c=read();
		d[u]-=c; d[v]+=c;
		if (c<=f){
			addedge(u,v,f-c,1);
			addedge(u,v,INF,2);
			addedge(v,u,c,1);
		}
		else{
			ans+=c-f;
			addedge(u,v,INF,2);
			addedge(v,u,c-f,0);
			addedge(v,u,f,1);
		}
	}
	addedge(1,n,INF,0); addedge(n,1,INF,0);
	S=n+1,T=S+1;
	rep(i,1,n)
		if (d[i]<0) addedge(i,T,-d[i],0);
		else if (d[i]>0) addedge(S,i,d[i],0);
	ans+=mcmf();
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}