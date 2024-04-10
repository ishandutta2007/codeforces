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

Vi v[300005];
int n,k,par[300001],ans;
char s[300005];
struct node {
	int l, r, on;
	node(int _l = 0, int _r = 0, int _on = 0) :l(_l), r(_r), on(_on) {}
	int find() {
		return min(l, r);
	}
}t[300005];
void merge(node &N, node M)
{
	N.l = min(INF, N.l + M.l);
	N.r = min(INF, N.r + M.r);
}
Pi g(int x)
{
	if (par[x] == x)return mp(x, 0);
	Pi tmp = g(par[x]);
	par[x] = tmp.X;
	t[x].on ^= tmp.Y;
	return mp(par[x], t[x].on);
}
int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	fup(i, 1, k, 1)
	{
		par[i] = i;
		t[i] = node(1, 0, 0);
		int tt;
		scanf("%d", &tt);
		while (tt--)
		{
			int x;
			scanf("%d", &x);
			v[x].pb(i);
		}
	}
	fup(i, 1, n, 1)
	{
		int rev = s[i] == '0';
		if (v[i].size() == 1)
		{
			Pi p = g(v[i][0]);
			ans -= t[p.X].find();
			merge(t[p.X], node((p.Y == rev)*INF, (p.Y != rev)*INF));
			ans += t[p.X].find();
		}
		else if (v[i].size() == 2)
		{
			Pi p1 = g(v[i][0]), p2 = g(v[i][1]);
			if (p1.X != p2.X)
			{
				ans -= t[p1.X].find() + t[p2.X].find();
				if (p1.Y ^ p2.Y ^ rev)
				{
					swap(t[p2.X].l, t[p2.X].r);
					t[p2.X].on = 1;
				}
				par[p2.X] = p1.X;
				merge(t[p1.X], t[p2.X]);
				ans += t[p1.X].find();
			}
		}
		printf("%d\n", ans);
	}
}