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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 9901;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool prime[1000001];
Vi p;
int n, t;
int N;
bool ok(int x)
{
	for (int i = 0; i < N && p[i] < x; i++)
	{
		int tt = ((x-1) / p[i]+1)*p[i];
		if (tt >= t && tt < n)return 1;
	}
	return 0;
}
int main()
{
	fill(prime + 2, prime + 1000001, true);
	fup(i, 2, 1000000, 1)
	{
		if (!prime[i])continue;
		fup(j, i+i, 1000000, i)
		{
			if (j != i)prime[j] = 0;
		}
	}
	fup(i, 2, 1000000, 1)if (prime[i])p.push_back(i);
	N = p.size();
	scanf("%d", &n);
	for (int i = 0; i < N && p[i] < n; i++)
	{
		if (n%p[i] == 0)t = n - p[i] + 1;
	}
	int l = 1, r = n-2;
	while (l <= r)
	{
		int x = (l + r) / 2;
		if (ok(x))r = x - 1;
		else l = x +1;
	}
	printf("%d", l);
}