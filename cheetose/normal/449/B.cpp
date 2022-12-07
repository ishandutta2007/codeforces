#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,k;
VPi v[100001];
bool cc[100000],chk[100001];
ll dist[100001];
int main() {
	fill(dist,dist+100001,INF);
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,m-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	int ans=0;
	fup(i,0,k-1,1)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		dist[x]=min(dist[x],y);
		if(cc[x])ans++;
		cc[x]=1;
	}
	priority_queue<Pll> q;
	dist[1] = 0;
	fup(i,1,n,1)if(dist[i]!=INF)q.push({-dist[i],i});
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			int next = p.X, cost = p.Y;
			if (dist[next] >= dist[x]+cost)
			{
				dist[next] = dist[x] + cost;
				if(cc[next])
				{
					ans++;
					cc[next]=0;
				}
				q.push({ -dist[next],next });
			}
		}
	}
	printf("%d",ans);
}