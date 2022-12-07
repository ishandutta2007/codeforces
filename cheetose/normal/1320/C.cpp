#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

VPll v[1000005];
ll tree[2097152];
ll a[1000005],b[1000005], lazy[2097152];
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = -b[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		tree[node] += val;
		if (S != E)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return -INF;
	if (j >= E && i <= S) return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	fill(tree,tree+2097152,-INF);
	fill(a,a+1000005,INF);fill(b,b+1000005,INF);
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	fup(i,1,n,1)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--;
		a[x]=min(a[x],y);
	}
	fup(i,1,m,1)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--;
		b[x]=min(b[x],y);
	}
	fdn(i,999999,0,1)
	{
		a[i]=min(a[i],a[i+1]);
		b[i]=min(b[i],b[i+1]);
	}
	fup(i,1,p,1)
	{
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		v[x].pb(mp(y,z));
	}
	ll ans=-INF;
	init(1,0,1000000);
	fup(i,0,1000000,1)
	{
		for(auto P:v[i])
		{
			upd(1,0,1000000,P.X,1000000,P.Y);
		}
		propagation(1,0,1000000);
		ans=max(ans,tree[1]-a[i]);
	}
	printf("%lld",ans);
}