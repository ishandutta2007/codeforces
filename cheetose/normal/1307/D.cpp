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

Vi vv;
int d[2][200005];
int n, m, k;
Vi v[200005];
void bfs(int c,int N)
{
	queue<int> q;
	d[c][N] = 0;
	q.push(N);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : v[x])
		{
			if (d[c][next] == -1)
			{
				d[c][next] = d[c][x] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	MEM_1(d);
	scanf("%d%d%d", &n, &m, &k);
	fup(i, 1, k, 1)
	{
		int x;
		scanf("%d", &x);
		vv.pb(x);
	}
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	bfs(0, 1); bfs(1, n);
	sort(ALL(vv), [&](int a, int b) {
		return d[0][a] < d[0][b];
	});
	int ans = d[0][n];
	set<Pi,greater<Pi> > S;
	for (int x : vv)
	{
		S.insert(mp(d[1][x], x));
	}
	int tmp = 0;
	for (int x : vv)
	{
		S.erase(mp(d[1][x], x));
		if (S.empty())break;
		tmp = max(tmp, d[0][x] + (*S.begin()).X + 1);
	}
	ans = min(ans, tmp);
	printf("%d", ans);
}