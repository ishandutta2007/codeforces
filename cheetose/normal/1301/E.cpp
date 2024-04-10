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
#define INF 987654321987654321
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
typedef pair<ld, ld> Pd;
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[505][505];
int r(char c)
{
	if (c == 'R')return 0;
	if (c == 'G')return 1;
	if (c == 'Y')return 2;
	return 3;
}
int c[5][505][505],res[505][505];
int n, m, q;
int cnt(int w, int x1, int y1, int x2, int y2)
{
	if (x1 <= 0 || y1 <= 0 || x2 > n || y2 > m)return 0;
	if (x1 > x2 || y1 > y2)return 0;
	return c[w][x2][y2] - c[w][x1 - 1][y2] - c[w][x2][y1 - 1] + c[w][x1 - 1][y1 - 1];
}
int ans[300000];
int x1[300000], y1[300000], x2[300000], y2[300000];
VPi v[505];
int main() {
	scanf("%d%d%d", &n, &m, &q);
	fup(i, 1, n, 1)scanf("%s", s[i]+1);
	fup(i, 1, n, 1)fup(j, 1, m, 1)c[r(s[i][j])][i][j]++;
	fup(k, 0, 3, 1)fup(i, 1, n, 1)fup(j, 1, m, 1)c[k][i][j] += c[k][i - 1][j] + c[k][i][j - 1] - c[k][i - 1][j - 1];
	fup(i, 1, n-1, 1)fup(j, 1, m-1, 1)
	{
		for (int &k = res[i][j]; k <= min(n, m); k++)
		{
			if (cnt(0, i - k, j - k, i, j) != (k + 1)*(k + 1) || cnt(1, i - k, j + 1, i, j + 1 + k) != (k + 1)*(k + 1) || cnt(2, i + 1, j - k, i + 1 + k, j) != (k + 1)*(k + 1) || cnt(3, i + 1, j + 1, i + 1 + k, j + 1 + k) != (k + 1)*(k + 1))break;
		}
	}
	fup(i, 0, q - 1, 1)
	{
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		x2[i]--, y2[i]--;
	}
	fup(i, 1, n - 1, 1)
	{
		fup(j, 1, m - 1, 1)if (res[i][j] > 0)v[res[i][j]].pb(mp(i, j));
	}
	VPi now;
	fdn(k, min(n,m), 1, 1)
	{
		for (Pi &p : v[k])now.pb(p);
		for (Pi &p : now)c[4][p.X][p.Y]++;
		fup(i, 1, n, 1)fup(j, 1, m, 1)c[4][i][j] += c[4][i - 1][j] + c[4][i][j - 1] - c[4][i - 1][j - 1];
		fup(i, 0, q - 1, 1)
		{
			int xx1 = x1[i] + k - 1, yy1 = y1[i] + k - 1, xx2 = x2[i] - k + 1, yy2 = y2[i] - k + 1;
			ans[i] = max(ans[i], cnt(4, xx1, yy1, xx2, yy2) ? k : 0);
		}
		MEM0(c[4]);
	}
	fup(i, 0, q - 1, 1)printf("%d\n", ans[i] * ans[i] * 4);
}