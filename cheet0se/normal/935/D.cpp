#include<cstdio>
#include<cstdlib>
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
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
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
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[100000], b[100000];
ll cnt[100001];
ll d[100000][3];
ll n, m;
ll go(int N, int c)
{
	if (c == 0)return 0;
	if (c == 2)return POW(m, cnt[N], MOD);
	if (N == n)return 0;
	ll &ret = d[N][c];
	if (ret != -1)return ret;
	ret = 0;
	if (a[N] == 0 && b[N] == 0)
	{
		ret = (ret + (m*go(N+1,1) % MOD)) % MOD;
		ret = ((((((m*m - m) / 2) % MOD)*go(N + 1, 2)) % MOD) + ret) % MOD;
	}
	else if (a[N] != 0 && b[N] == 0)
	{
		ret = (ret + go(N + 1, 1)) % MOD;
		ret = (ret + ((a[N] - 1)*go(N + 1, 2)) % MOD) % MOD;
	}
	else if (a[N] == 0 && b[N] != 0)
	{
		ret = (ret + go(N + 1, 1)) % MOD;
		ret = (ret + ((m- b[N])*go(N + 1, 2)) % MOD) % MOD;
	}
	else
	{
		if (a[N] > b[N])ret = go(N + 1, 2);
		else if (a[N] < b[N])ret = go(N + 1, 0);
		else ret = go(N + 1, 1);
	}
	return ret;
}
int main()
{
	MEM_1(d);
	scanf("%I64d%I64d", &n, &m);
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	fup(i, 0, n - 1, 1)scanf("%d", b + i);
	fdn(i, n - 1, 0, 1)
	{
		cnt[i] = cnt[i + 1];
		if (a[i] == 0)cnt[i]++;
		if (b[i] == 0)cnt[i]++;
	}
	ll p = go(0, 1);
	ll q = POW(m, cnt[0], MOD);
	printf("%I64d", (p*POW(q, MOD - 2, MOD)) % MOD);
}