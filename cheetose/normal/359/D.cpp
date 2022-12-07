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
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[300000], gcdd[19][300000], mind[19][300000];
int n;
int minfind(int i, int m)
{
	int res = INF;
	fdn(ii, 18, 0, 1)
	{
		if (m&(1 << ii))
		{
			res = min(res, mind[ii][i]);
			i += (1 << ii);
		}
	}
	return res;
}
bool gcdfind(int i, int m, int k)
{
	fdn(ii, 18, 0, 1)
	{
		if (m&(1 << ii))
		{
			if (gcdd[ii][i] % k)return 0;
			i += (1 << ii);
		}
	}
	return 1;
}
bool ok(int m)
{
	fup(i, 0, n - 1 - m, 1)
	{
		int k = minfind(i, m+1);
		if (gcdfind(i, m+1, k))return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", a + i);
		gcdd[0][i] = a[i];
		mind[0][i] = a[i];
	}
	fup(i, 1, 18, 1)
	{
		fup(j, 0, n - 1, 1)
		{
			if (j + (1 << (i - 1)) >= n)break;
			gcdd[i][j] = gcd(gcdd[i - 1][j], gcdd[i - 1][j + (1 << (i - 1))]);
			mind[i][j] = min(mind[i - 1][j], mind[i - 1][j + (1 << (i - 1))]);
		}
	}
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (ok(m))l = m + 1;
		else r = m - 1;
	}
	Vi ans;
	fup(i, 0, n - 1 - r, 1)
	{
		int k = minfind(i, r+1);
		if (gcdfind(i, r+1, k))ans.push_back(i + 1);
	}
	printf("%d %d\n", ans.size(), r);
	for (int x : ans)printf("%d ", x);
}