#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 100000LL
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

ll a[100001];
ll next(ll n, ll x)
{
	if (n%x == 0)return n;
	return (n / x + 1)*x;
}
int main() {
	int n;
	ll x, k;
	scanf("%d%I64d%I64d", &n, &x, &k);
	fup(i, 0, n - 1, 1)scanf("%I64d", a + i);
	sort(a, a + n);
	ll ans = 0;
	if (k != 0)
	{
		fup(i, 0, n - 1, 1)
		{
			ll t = next(a[i], x);
			ans += lower_bound(a, a + n, t + x*k) - lower_bound(a, a + n, t + x*(k - 1));
		}
	}
	else
	{
		fup(i, 0, n - 1, 1)
		{
			ll t = next(a[i], x);
			if (t == a[i])continue;
			ans += lower_bound(a, a + n, t) - lower_bound(a, a + n, a[i]);
		}
	}
	printf("%I64d", ans);
}