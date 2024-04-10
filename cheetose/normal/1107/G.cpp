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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct Node {
	ll lsum, rsum, maxsum, sum;
};
Node tree[1048576];
void upd(int node, int S, int E, int i, ll k)
{
	if (S == E)
	{
		tree[node].lsum = k;
		tree[node].rsum = k;
		tree[node].maxsum = k;
		tree[node].sum = k;
		return;
	}
	if (i <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, i, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, i, k);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
}
Node find(int node, int S, int E, int i, int j)
{
	Node T = { -INF,-INF,-INF,-INF };
	if (i > E || j < S)return T;
	if (i <= S && j >= E)return tree[node];
	Node L = find(node * 2, S, (S + E) / 2, i, j);
	Node R = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if (L.lsum == T.lsum)return R;
	if (R.lsum == T.lsum)return L;
	T.lsum = max(L.lsum, L.sum + R.lsum);
	T.rsum = max(R.rsum, R.sum + L.rsum);
	T.sum = L.sum + R.sum;
	T.maxsum = max({ L.maxsum, R.maxsum, L.rsum + R.lsum });
	return T;
}
Pi p[300000];
set<Pi> S;
int main() {
	int n,x;
	scanf("%d%d", &n, &x);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d%d", &p[i].X, &p[i].Y);
		p[i].Y = x - p[i].Y;
	}
	fup(i, 0, n - 1, 1)upd(1, 0, n - 1, i, p[i].Y);
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		S.insert(mp(i, i));
		ans = max(ans, (ll)p[i].Y);
	}
	VPi v;
	fup(i, 0, n - 2, 1)
	{
		v.push_back(mp(p[i + 1].X - p[i].X, i));
	}
	sort(ALL(v));
	int l = 0, r = 0;
	int N = v.size();
	while (l < N)
	{
		r = l;
		while (r + 1< N && v[l].X == v[r+1].X)r++;
		ll d = 1LL * v[l].X*v[l].X;
		fup(i, l, r, 1)
		{
			auto it = S.lower_bound(mp(v[i].Y, 987654321));
			auto R = *it;
			it--;
			auto L = *it;
			S.erase(L); S.erase(R);
			ans = max(ans, find(1, 0, n - 1, L.X, R.Y).maxsum - d);
			S.insert(mp(L.X,R.Y));
		}
		l = r + 1;
	}
	printf("%lld", ans);
}