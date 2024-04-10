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
typedef tuple<int, int, int> iii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[1001];
int a[1000];
int d[1001];
ll dp[1000][1001][2];
int n;
int go(int N)
{
	if (N == 1)return 0;
	int &ret = d[N];
	if (ret != -1)return ret;
	int tt = bitset<11>(N).count();
	ret = 1 + go(tt);
	return ret;
}
ll go2(int N, int k, bool flag)
{
	if (N == n)return k==0;
	ll &ret = dp[N][k][flag];
	if (ret != -1)return ret;
	ret = 0;
	if (flag)
	{
		ret = (ret + go2(N + 1, k, flag)) % MOD;
		if (k > 0)ret = (ret + go2(N + 1, k - 1, flag)) % MOD;
	}
	else
	{
		if(a[N]==0)
			ret = (ret + go2(N + 1, k, flag)) % MOD;
		else ret = (ret + go2(N + 1, k, 1)) % MOD;
		if(k>0 && a[N]==1)ret = (ret + go2(N + 1, k-1, flag)) % MOD;
	}
	return ret;
}
int main() {
	MEM_1(d);
	MEM_1(dp);
	d[1] = 0;
	scanf("%s", s);
	n = strlen(s);
	fup(i,0,n-1,1)
	{
		a[i] = s[i] - '0';
	}
	fup(i, 1, 1000, 1)
		go(i);
	int k;
	scanf("%d", &k);
	if (k == 0)
	{
		puts("1");
		return 0;
	}
	if (k == 1)
	{
		printf("%d", n - 1);
		return 0;
	}
	ll ans = 0;
	fup(i, 1, 1000, 1)
	{
		if (d[i] == k-1)
		{
			ans = (ans + go2(0, i, 0)) % MOD;
		}
	}
	printf("%I64d", ans);
}