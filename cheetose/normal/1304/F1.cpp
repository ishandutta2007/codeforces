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

int d[55][20005];
int s[55][20005];
int L[55][20005], R[55][20005];
int n, m, k;
int sum(int x1, int y1, int x2, int y2)
{
	y1 = max(y1, 1), y2 = min(y2, m);
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	fup(i,1,n,1)
		fup(j, 1, m, 1)
	{
		scanf("%d", &s[i][j]);
	}
	fup(i,1,n+2,1)
		fup(j, 1, m, 1)
	{
		s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
	}
	fup(i, 1, m - k + 1, 1)d[1][i] = sum(1, i, 2, i + k - 1);
	fup(i, 1, m - k + 1, 1)L[1][i] = max(L[1][i - 1], d[1][i]);
	fdn(i, m - k + 1, 1, 1)R[1][i] = max(R[1][i + 1], d[1][i]);
	fup(i, 2, n, 1)
	{
		fup(j, 1, m - k + 1, 1)
		{
			int box = sum(i, j, i + 1, j + k - 1);
			int l = max(1, j - k + 1), r = min(m - k + 1, j + k - 1);
			d[i][j] = max(L[i - 1][l - 1], R[i - 1][r + 1]) + box;
			fup(jj, l, r, 1)
			{
				if (jj < j)
				{
					d[i][j] = max(d[i][j], d[i - 1][jj] + box - sum(i, j, i, jj + k - 1));
				}
				else
				{
					d[i][j] = max(d[i][j], d[i - 1][jj] + box - sum(i, jj, i, j + k - 1));
				}
			}
		}
		fup(j, 1, m - k + 1, 1)L[i][j] = max(L[i][j - 1], d[i][j]);
		fdn(j, m - k + 1, 1, 1)R[i][j] = max(R[i][j + 1], d[i][j]);
	}
	printf("%d", L[n][m - k + 1]);
}