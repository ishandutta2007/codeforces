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
#define MOD 1000000007
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

int len(int n)
{
	if (n == 0)return 1;
	int c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return c;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 4)
	{
		printf("%d", n*(n - 1) / 2);
		return 0;
	}
	int tt = n;
	while (tt % 10 == 0)
		tt /= 10;
	if (tt == 5)
	{
		puts("1");
		return 0;
	}
	ll MAX = 2LL * n - 1;
	int c9 = len(MAX) - 1;
	ll init = 0;
	while (c9--)
	{
		init *= 10;
		init += 9;
	}
	ll pp = init + 1;
	ll ans = 0;
	for(ll i=init;i<=MAX;i+=pp)
	{
		ll r = min(i,(ll)n);
		ll l = max(1LL,i - r);
		ans += (r - l + 1) / 2;
	}
	printf("%I64d", ans);
}