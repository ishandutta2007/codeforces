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

int a[200001];
Vi tree[524288];
Vi merge(const Vi& v1, const Vi& v2)
{
	Vi v;
	int i = 0, j = 0, n = v1.size(), m = v2.size();
	while (1)
	{
		if (i == n && j == m)break;
		if (i == n) v.push_back(v2[j++]);
		else if (j == m)v.push_back(v1[i++]);
		else if (v1[i] > v2[j]) v.push_back(v2[j++]);
		else v.push_back(v1[i++]);
	}
	return v;
}
int n;
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node].push_back(min(a[S],n));
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
int find(int node, int S, int E, int i, int j, int k)
{
	if (i > E || j < S) return 0;
	if (S == E)
	{
		if (a[S] >= k)return 1;
		else return 0;
	}
	if (j >= E && i <= S) return tree[node].end() - lower_bound(tree[node].begin(), tree[node].end(), k);
	return find(2 * node, S, (S + E) / 2, i, j, k) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j, k);
}
int main() {
	scanf("%d", &n);
	fup(i, 1, n, 1)
		scanf("%d", a + i);
	init(1, 1, n);
	ll ans = 0;
	fup(i, 1, n, 1)
	{
		ans += find(1, 1, n, 1, min(i - 1, a[i]), i);
	}
	printf("%lld", ans);
}