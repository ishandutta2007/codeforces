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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll p[101], inv[101];
ll a[200002];
int LRtree[524288];
void upd(int node, int S, int E,int i, int k)
{
	LRtree[node] += k;
	if (S == E)return;
	int M = (S + E) >> 1;
	if(i<=M)upd(node << 1, S, M, i, k);
	else upd(node << 1 | 1, M + 1, E, i, k);
}
int findsum(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return LRtree[node];
	return findsum(node * 2, S, (S + E) / 2, i, j) + findsum(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

int findK(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= LRtree[node * 2])return findK(node * 2, S, (S + E) / 2, k);
	return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - LRtree[node * 2]);
}
struct Node {
	ll t1, t2;
};
Node merge(Node n1, Node n2) {
	Node T;
	T.t1 = (n1.t1*n2.t1) % MOD;
	T.t2 = (n1.t1*n2.t2+n1.t2) % MOD;
	return T;
}

Node tree[524288];

void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = { a[S],1 };
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
ll res(Node N) {
	return (N.t2*POW(N.t1,MOD-2)) % MOD;
}

Node find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return{ 1,0 };
	if (i <= S && j >= E)return tree[node];
	return merge(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
bool chk[200002];
int main() {
	ll tmp = POW(100, MOD - 2);
	fup(i, 1, 100, 1)p[i] = (tmp*i) % MOD;
	int n, q;
	scanf("%d%d", &n, &q);
	fup(i, 1, n, 1)
	{
		int x;
		scanf("%d", &x);
		a[i] = p[x];
	}
	init(1, 1, n);
	ll ans = res(tree[1]);
	upd(1, 1, n + 1, 1, 1);
	upd(1, 1, n + 1, n+1, 1);
	chk[1] = chk[n + 1] = 1;
	while (q--)
	{
		int x;
		scanf("%d", &x);
		int L = findK(1, 1, n + 1, LRtree[1]- findsum(1, 1, n + 1, x, n + 1));
		int R = findK(1, 1, n + 1, findsum(1, 1, n + 1, 1, x) + 1) - 1;
		if (chk[x])
		{
			ans = (ans - res(find(1, 1, n, L, x - 1)) - res(find(1, 1, n, x, R)) + res(find(1, 1, n, L, R)) + MOD*MOD + 1) % MOD;
			upd(1, 1, n + 1, x, -1);
		}
		else
		{
			ans = (ans + res(find(1, 1, n, L, x - 1)) + res(find(1, 1, n, x, R)) - res(find(1, 1, n, L, R)) + MOD*MOD + 1) % MOD;
			upd(1, 1, n + 1, x, 1);
		}
		chk[x] ^= 1;
		printf("%lld\n", ans);
	}
}