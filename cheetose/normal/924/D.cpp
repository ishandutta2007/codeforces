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
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
 
struct fra {
	ll a, b;
	bool operator < (const fra &O) { return a*O.b < b*O.a; }
	bool operator > (const fra &O) { return a*O.b > b*O.a; }
	bool operator ==(const fra &O) { return a == O.a && b == O.b; }
	bool operator !=(const fra &O) { return a != O.a || b != O.b; }
};
bool operator < (const fra &L,const fra &R) { return L.a*R.b < L.b*R.a; }
pair<fra, fra> p[100000];
map<fra, int> M;
int tree[262144];
void upd(int node, int S, int E, int k, int dif)
{
	tree[node] += dif;
	if (S == E)return;
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
}
int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	int n, w;
	scanf("%d%d", &n, &w);
	fup(i, 0, n - 1, 1)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll a = -x, b = y - w;
		if (a < 0)a *= -1, b *= -1;
		ll t = gcd(a, b);
		p[i].X = { a / t,b / t };
		a = -x, b = y + w;
		if (a < 0)a *= -1, b *= -1;
		t = gcd(a, b);
		p[i].Y = { a / t,b / t };
	}
	vector<fra> v;
	fup(i, 0, n - 1, 1)
		v.push_back(p[i].Y);
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	int N = v.size();
	fup(i, 0, N - 1, 1)
		M[v[i]] = i;
	sort(p, p + n, [&](pair<fra, fra> a1, pair<fra, fra> a2) {
		if (a1.X != a2.X)return a1.X < a2.X;
		return a1.Y > a2.Y;
	});
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		int t=M[p[i].Y];
		ans += find(1, 0, N - 1, t, N - 1);
		upd(1, 0, N - 1, t, 1);
	}
	printf("%lld", ans);
}