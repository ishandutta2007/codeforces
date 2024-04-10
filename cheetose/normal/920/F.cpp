#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 900528LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b, ll p) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1, p)) % p; ll t = POW(a, b / 2, p); return (t*t) % p; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if (b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll tree[1048576];
int a[300000];
int d[1000001];
set<int> S;
set<int>::iterator it,it2;
void upd(int node, int S, int E, int k, ll dif)
{
	if (S == E)
	{
		tree[node] = dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, 1000000, 1)
		fup(j, i, 1000000, i)d[j]++;
	fup(i, 0, n - 1, 1)
	{
		scanf("%lld", a + i);
		upd(1, 0, n - 1, i, a[i]);
		if (a[i] >= 3)S.insert(i);
	}
	while (m--)
	{
		int c, x, y;
		scanf("%d%d%d", &c, &x, &y);
		x--, y--;
		if (c == 1)
		{
			it = S.lower_bound(x);
			while (it != S.end() && *it <= y)
			{
				int i = *it;
				a[i] = d[a[i]];
				upd(1, 0, n - 1, i, a[i]);
				it2 = it;
				it++;
				if (a[i] <= 2)
					S.erase(it2);
			}
		}
		else
		{
			printf("%lld\n", find(1, 0, n - 1, x, y));
		}
	}
}