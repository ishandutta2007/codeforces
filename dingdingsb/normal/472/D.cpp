// : caigou
// : 2021-11-15 09:15

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=2500+100;
int T,n;ll dis[N][N];
struct fenshu{
	ll a,b;
	bool operator<(const fenshu&rhs)const{return a*rhs.b<rhs.a*b;}
};
pair<fenshu,int>mx;
vector<pair<int,int>>e[N];
int dep[N];
void dfs(int u,int fa){
	int v,w;
	for(auto E:e[u]){
		tie(v,w)=E;
		if(v==fa)continue;
		dep[v]=dep[u]+w;dfs(v,u);
	}
}
bool chk(int u){
	dep[u]=0;dfs(u,0);
	for(int i=1;i<=n;i++)if(dep[i]!=dis[u][i])return false;
	return true;
}
pair<int,int>mn[N];bool vis[N];
int sum[N];
void add(int u,int v,int w){
	sum[u]+=w,sum[v]+=w;
	e[u].pb(mp(v,w));
	e[v].pb(mp(u,w));
}
void work(){
	read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			read(dis[i][j]);
			if(i!=j&&dis[i][j]==0)return puts("NO"),void();
		}
	for(int i=1;i<=n;i++)e[i].clear(),vis[i]=0,sum[i]=0;
	vis[1]=1;
	for(int i=2;i<=n;i++)mn[i]=mp(dis[1][i],1);
	for(int kk=1;kk<n;kk++){
		pair<pair<int,int>,int>now=mp(mp(0x3f3f3f3f3f3f3f3f,0),0);
		for(int i=1;i<=n;i++)if(!vis[i])
			chkmn(now,mp(mn[i],i));
		vis[now.se]=1;
		add(now.se,now.fi.se,now.fi.fi);
		for(int i=1;i<=n;i++)
			chkmn(mn[i],mp(dis[now.se][i],now.se));
	}
	for(int i=1;i<=n;i++)if(!chk(i))return puts("NO"),void();
	puts("YES");
}
signed main(){
	work();
}