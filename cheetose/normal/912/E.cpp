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
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

const ll MAXN = 1000000000000000000;
void precal(Vll &in, Vll &out, int i, ll now)
{
	if (i == in.size())
	{
		out.push_back(now);
		return;
	}
	while (1)
	{
		precal(in, out, i + 1, now);
		if (now > MAXN / in[i])break;
		now *= in[i];
	}
}
Vll A,B;
ll k;
bool ok(ll m)
{
	ll cnt = 0;
	int idx = 0;
	for (ll x : A)
	{
		while (idx < B.size() && x <= m / B[idx])idx++;
		cnt += idx;
	}
	return cnt >= k;
}
int main()
{
	Vll a[2];
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		ll x;
		scanf("%I64d", &x);
		a[i % 2].push_back(x);
	}
	precal(a[0], A, 0, 1);
	precal(a[1], B, 0, 1);
	sort(A.rbegin(),A.rend());
	sort(ALL(B));
	scanf("%I64d", &k);
	ll l = 0, r = MAXN;
	while (l <= r)
	{
		ll m = (l + r) / 2;
		if (ok(m))r = m - 1;
		else l = m + 1;
	}
	printf("%I64d", l);
}