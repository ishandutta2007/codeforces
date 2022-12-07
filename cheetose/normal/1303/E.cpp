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
#define INF 987654321
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

char s[405],t[405];
int d[402][402],n,m;
short dd[402][402][402];
short ne[26][402],pr[26];
int go(int N, int M)
{
	if (M > m)return 1;
	if (N > n)return 0;
	int &ret = d[N][M];
	if (~ret)return ret;
	ret = go(N+1,M);
	if (s[N] == t[M])ret = max(ret, go(N + 1, M + 1));
	return ret;
}
void solve() {
	MEM_1(d);
	scanf("%s%s", s+1, t+1);
	n = strlen(s+1), m = strlen(t+1);
	if (go(1, 1))
	{
		puts("YES");
		return;
	}
	fup(i, 0, 25, 1)pr[i] = n+1;
	fup(i, 0, 25, 1)ne[i][n + 1] = n + 1;
	fdn(i, n, 0, 1)
	{
		fup(j, 0, 25, 1)ne[j][i] = pr[j];
		if(i)pr[s[i] - 'a'] = i;
	}
	fup(i, 0, m + 1, 1)fup(j, 0, m + 1, 1)fup(k, 0, m + 1, 1)
	{
		if(i==0 && k==j)dd[i][j][k] = 0;
		else dd[i][j][k] = n + 1;
	}
	fup(r, 1, m - 1, 1)
	{
		fup(a,0,r,1)
			fup(b, r, m, 1)
		{
			if(a<r)dd[a + 1][r][b] = min(dd[a + 1][r][b], ne[t[a + 1] - 'a'][dd[a][r][b]]);
			if(b<m)dd[a][r][b + 1] = min(dd[a][r][b + 1], ne[t[b + 1] - 'a'][dd[a][r][b]]);
		}
	}
	fup(r, 1, m - 1, 1)if (dd[r][r][m] <= n)
	{
		puts("YES");
		return;
	}
	puts("NO");
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}