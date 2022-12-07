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
#define y0 y12
#define y1 y22
#define INF 1987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll fac[200001];
ll inv[200001];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
Pll p[200000];
Vll vv;
ll tree[600005],sz[600005];
int N;
void upd(int i, int k)
{
	while (i <= N)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
ll sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 200000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[200000] = POW(fac[200000], MOD - 2);
	fdn(i, 199999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)
	{
		scanf("%lld%lld",&p[i].X,&p[i].Y);
		vv.pb(p[i].X);
		vv.pb(p[i].Y);
		vv.pb(p[i].Y+1);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	N=vv.size();
	fup(i,0,n-1,1)
	{
		p[i].X=lower_bound(ALL(vv),p[i].X)-vv.begin()+1;
		p[i].Y=lower_bound(ALL(vv),p[i].Y)-vv.begin()+1;
		upd(p[i].X,1);
		upd(p[i].Y+1,-1);
	}
	fup(i,1,N-1,1)sz[i]=vv[i]-vv[i-1];
	ll ans=0;
	fup(i,1,N-1,1)ans=(ans+sz[i]*nCr(sum(i),k))%MOD;
	printf("%lld",ans);
}