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
#define INF 1987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

bool chk[2001];
int um[2001];
int d[2001][2002];
int k, n, m;
int go(int N, int M)
{
	if (N == k)return 0;
	int &ret = d[N][M];
	if (ret != -1)return ret;
	ret = INF;
	if (M == 2001)
	{
		if (chk[N] && um[N] == -1)return ret = INF;
		if(!chk[N])ret = min(ret, go(N + 1, 2001));
		if(um[N]!=-1)ret = min(ret, um[N] + go(N + 1, N));
		return ret;
	}
	ret = min(ret, um[M] + go(N + 1, M));
	if (!chk[N])ret = min(ret, go(N + 1, 2001));
	if (um[N] != -1)ret = min(ret, um[N] + go(N + 1, N));
	return ret;
}
int main() {
	MEM_1(um);
	MEM_1(d);
	scanf("%d%d%d", &k, &n, &m);
	fup(i, 1, n, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fup(ii, x, y-1, 1)chk[ii] = 1;
	}
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (um[x] == -1)um[x] = y;
		else um[x] = min(um[x], y);
	}
	printf("%d", go(0, 2001)==INF?-1:go(0,2001));
}