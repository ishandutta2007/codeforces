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
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
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
typedef vector<iii> Viii;
typedef complex<double> base;
int MOD = 10001;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

VPi v;
int N;
int a[100000];
int c[9][100000], sum[9][100000];
bool ok(int L,int R)
{
	N = v.size();
	fup(k, 0, N - 1, 1)
	{
		int cc = sum[k][R];
		if (L != 0)cc -= sum[k][L - 1];
		if (cc < v[k].Y)return 0;
	}
	return 1;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 2; i*i <= k; i++)
	{
		if (k%i == 0)
		{
			int c = 0;
			while (k%i == 0)
			{
				k /= i;
				c++;
			}
			v.push_back({ i,c });
		}
	}
	if (k != 1)v.push_back({ k,1 });
	int N = v.size();
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	fup(i, 0, n - 1, 1)
	{
		int t = a[i];
		fup(k, 0, N - 1, 1)
		{
			int cc = v[k].X;
			while (t%cc == 0)
			{
				t /= cc;
				c[k][i]++;
			}
		}
	}
	fup(k, 0, N - 1, 1)
	{
		fup(i, 0, n - 1, 1)
		{
			if (i == 0)sum[k][i] = c[k][i];
			else sum[k][i] = sum[k][i - 1] + c[k][i];
		}
	}
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		int l = i, r = n - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (ok(i, m))r = m - 1;
			else l = m + 1;
		}
		ans += n - l;
	}
	printf("%lld", ans);
}