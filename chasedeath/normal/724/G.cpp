#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef long long ll;
#define reg register
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
inline int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=5e5+10,E=2e5+10,P=1e9+7;

int n,m;

struct Edge{
	int to,nxt;
	ll w;
}e[E<<1];
int head[N],ecnt;
void AddEdge(int u,int v,ll w){
	e[++ecnt]=(Edge){v,head[u],w};
	head[u]=ecnt;
}
#define erep(u,i) for(int i=head[u];i;i=e[i].nxt)



ll dis[N];
int vis[N];
int cnt[70][2];
ll tmp[70][2];
vector <int> Points;
vector <ll> cir;
void dfs(int u){
	Points.push_back(u);
	rep(i,0,60) if(dis[u]&(1ll<<i)) cnt[i][1]++;
	else cnt[i][0]++;
	vis[u]=1;
	erep(u,i) {
		int v=e[i].to;
		if(vis[v]) {
			cir.push_back(dis[v]^dis[u]^e[i].w);
			continue;
		}
		dis[v]=dis[u]^e[i].w;
		dfs(v);
	}
}


ll Ans;
ll d[70];
bool Ins(ll d[],ll x){
	drep(i,60,0) if(x&(1ll<<i)) {
		if(d[i]) x^=d[i];
		else {
			d[i]=x;
			return true;
		}
	}
	return false;
}
void Solve(int rt){
	Points.clear();cir.clear();
	memset(cnt,0,sizeof cnt);memset(d,0,sizeof d); memset(tmp,0,sizeof tmp);
	dfs(rt);
	rep(k,0,(int)Points.size()-1) {
		ll t=dis[Points[k]];
		rep(i,0,60) if(t&(1ll<<i)) cnt[i][1]--;
		else cnt[i][0]--;
		rep(i,0,60) {
			if(t&(1ll<<i)) tmp[i][0]+=cnt[i][1],tmp[i][1]+=cnt[i][0];
			else tmp[i][0]+=cnt[i][0],tmp[i][1]+=cnt[i][1];
			tmp[i][0]%=P,tmp[i][1]%=P;
		}
		rep(i,0,60) if(t&(1ll<<i)) cnt[i][1]++;
		else cnt[i][0]++;
	}
	rep(i,0,(int)cir.size()-1) {
		ll t=cir[i];
		if(!Ins(d,t)) continue;
		rep(i,0,60) {
			if(t&(1ll<<i)) {
				ll t=(tmp[i][0]+tmp[i][1])%P;
				tmp[i][0]=tmp[i][1]=t;
			} else tmp[i][0]*=2,tmp[i][1]*=2;
			tmp[i][0]%=P,tmp[i][1]%=P;
		}
	}
	rep(i,0,60) {
		ll b=(1ll<<i)%P;
		(Ans+=tmp[i][1]%P*b%P)%=P;
	}
}








signed main() {
	n=rd(),m=rd();
	rep(i,1,m) {
		int u=rd(),v=rd();
		ll w; scanf("%lld",&w);
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	rep(i,1,n) if(!vis[i]) Solve(i);
	printf("%lld\n",Ans*500000004%P);
}