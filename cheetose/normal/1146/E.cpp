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

int tree[262144], lazy1[262144], lazy2[262144];
int a[100001];
void propagation(int node, int S, int E)
{
	tree[node] = tree[node] * lazy1[node] + lazy2[node];
	if (S != E)
	{
		fup(next, node * 2, node * 2 + 1, 1)
		{
			lazy1[next] = lazy1[next] * lazy1[node];
			lazy2[next] = lazy2[next] * lazy1[node] + lazy2[node];
		}
	}
	lazy1[node] = 1, lazy2[node] = 0;
}
void upd(int node, int S, int E, int i, int j, int p1, int p2)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		if (p1 == 1)
		{
			lazy2[node] = lazy2[node] + p2;
		}
		else if (p1 == 2)
		{
			lazy1[node] = lazy1[node] * p2;
			lazy2[node] = lazy2[node] * p2;
		}
		else
		{
			lazy1[node] = 0, lazy2[node] = p2;
		}
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, p1, p2);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, p1, p2);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	fill(lazy1, lazy1 + 262144, 1);
	fill(tree, tree + 262144, 1);
	int n, q, N=100000;
	scanf("%d%d", &n, &q);
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	fup(i, 0, q - 1, 1)
	{
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		if (c == '>')
		{
			if (x >= 0)
			{
				upd(1, 1, N, x + 1, N, 3, 3);
			}
			else
			{
				upd(1, 1, N, -x, N, 3, 3);
				upd(1, 1, N, 1, -x - 1, 2, -1);
				upd(1, 1, N, 1, -x - 1, 1, 3);
			}
		}
		else
		{
			if (x <= 0)
			{
				upd(1, 1, N, -x + 1, N, 3, 0);
			}
			else
			{
				upd(1, 1, N, x, N, 3, 0);
				upd(1, 1, N, 1, x - 1, 2, -1);
				upd(1, 1, N, 1, x - 1, 1, 3);
			}
		}
	}
	fup(i, 0, n - 1, 1)
	{
		if (a[i] == 0)printf("0 ");
		else
		{
			int x = a[i] > 0 ? a[i] : -a[i];
			int t = find(1, 1, N, x, x);
			if (a[i] > 0)printf("%d ", t & 2 ? -a[i] : a[i]);
			else printf("%d ", t & 1 ? a[i] : -a[i]);
		}
	}
}