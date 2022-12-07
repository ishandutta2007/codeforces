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
#define INF 98765
#define PI 3.141592653589793238462643383279502884
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[101];
Pi p[101];
struct A {
	int i, c, last;
	bool operator < (A &a) {
		if (c != a.c)return c > a.c;
		return last < a.last;
	}
}ori[101], tmp[101];
int main() {
	int n, K, m, s;
	scanf("%d%d%d%d", &n, &K, &m, &s);
	m -= s;
	fup(i, 1, s, 1)
	{
		scanf("%d", a + i);
		p[a[i]].X++;
		p[a[i]].Y = i;
	}
	fup(i, 1, n, 1)
	{
		ori[i].i = i, ori[i].c = p[i].X, ori[i].last = p[i].Y;
	}
	sort(ori + 1, ori + n + 1);
	if (m == 0)
	{
		int ans[101];
		fup(i, 1, n, 1)
		{
			if (i <= K && ori[i].c > 0)ans[ori[i].i] = 1;
			else ans[ori[i].i] = 3;
		}
		fup(i, 1, n, 1)printf("%d ", ans[i]);
		return 0;
	}
	fup(i, 1, n, 1)
	{
		memcpy(tmp + 1, ori + 1, n * sizeof(A));
		int k;
		fup(ii, 1, n, 1)if (tmp[ii].i == i)k = ii;
		tmp[k].c += m;
		tmp[k].last = m + s;
		sort(tmp + 1, tmp + n + 1);
		fup(ii, 1, n, 1)if (tmp[ii].i == i)k = ii;
		if (k > K)
		{
			printf("3 ");
			continue;
		}
		if (p[i].X == 0)
		{
			printf("2 ");
			continue;
		}
		memcpy(tmp + 1, ori + 1, n * sizeof(A));
		fup(ii, 1, n, 1)if (tmp[ii].i == i)k = ii;
		if (k <= K)
		{
			int tt = tmp[k].c;
			int cc = 0;
			fup(ii, k + 1, K + 1, 1)
				cc += tt - tmp[ii].c + 1;
			if (n==K || cc > m)
			{
				printf("1 ");
				continue;
			}
		}
		printf("2 ");
	}
}