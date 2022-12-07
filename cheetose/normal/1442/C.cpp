#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[200002],rev[200002];
int dist[200002][21];
ll dist2[400002];
bool chk[400002];
int main(){
	MEM_1(dist);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		rev[y].pb(x);
	}
	queue<Pi> q;
	q.push(mp(1,0));
	dist[1][0]=0;
	while(!q.empty()){
		auto [x,k]=q.front();
		q.pop();
		for(int next:(k&1?rev[x]:v[x])){
			if(dist[next][k]==-1){
				dist[next][k]=dist[x][k]+1;
				q.push(mp(next,k));
			}
		}
		if(k<=19){
			for(int next:(k&1?v[x]:rev[x])){
				if(dist[next][k+1]==-1){
					dist[next][k+1]=dist[x][k]+1;
					q.push(mp(next,k+1));
				}
			}
		}
	}
	int ans=INF;
	fup(i,0,20,1){
		if(dist[n][i]!=-1){
			ans=min(ans,dist[n][i]+(1<<i)-1);
		}
	}

	if(ans!=INF)return !printf("%d\n",ans);
	fup(i,1,2*n,1)dist2[i]=1e18;
	priority_queue<Pll> Q;
	dist2[1] = 0;
	Q.push({ 0,1 });
	while (!Q.empty())
	{
		int x = Q.top().Y;
		Q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		if(x>n){// 
			for(int next:rev[x-n]){
				ll cost=1;
				if(dist2[next+n]>dist2[x]+cost){
					dist2[next+n]=dist2[x]+cost;
					Q.push({-dist2[next+n],next+n});
				}
			}
			for(int next:v[x-n]){
				ll cost=1000001;
				if(dist2[next]>dist2[x]+cost){
					dist2[next]=dist2[x]+cost;
					Q.push({-dist2[next],next});
				}
			}
		}else{
			for(int next:v[x]){
				ll cost=1;
				if(dist2[next]>dist2[x]+cost){
					dist2[next]=dist2[x]+cost;
					Q.push({-dist2[next],next});
				}
			}
			for(int next:rev[x]){
				ll cost=1000001;
				if(dist2[next+n]>dist2[x]+cost){
					dist2[next+n]=dist2[x]+cost;
					Q.push({-dist2[next+n],next+n});
				}
			}
		}
	}
	ll dd=min(dist2[n],dist2[2*n]);
	ll re=dd/1000000,c=dd%1000000;
	ll res=1;
	fup(i,1,re,1)res=res*2%MOD;
	res+=c-1;
	res%=MOD;
	if(res<0)res+=MOD;
	printf("%lld\n",res);
}