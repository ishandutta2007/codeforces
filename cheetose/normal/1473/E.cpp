#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1000000000000000
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

VPll v[800000];
ll dist[800000];
bool chk[800000];
int n,m;
void addedge(int x,int y,ll z){
	fup(i,0,3,1){
		v[i*n+x].pb(mp(i*n+y,z));
	}
	if(x==0)v[x].pb(mp(3*n+y,z));
	v[x].pb(mp(n+y,2*z));
	v[x].pb(mp(2*n+y,0));
	v[2*n+x].pb(mp(3*n+y,2*z));
	v[n+x].pb(mp(3*n+y,0));
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,m,1){
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		x--,y--;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	priority_queue<Pll> q;
	fill(dist,dist+4*n,987654321987654321);
	dist[0] = 0;
	q.push({ 0,0 });
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			ll next = p.X, cost = p.Y;
			if (dist[next] > dist[x]+cost)
			{
				dist[next] = dist[x] + cost;
				q.push({ -dist[next],next });
			}
		}
	}fup(i,1,n-1,1)printf("%lld ",dist[3*n+i]);
}