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
#define pb push_back
#define X first
#define Y second
#define INF 2000000007
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 2,2,-2,-2 }, DY[] = { 2,-2,-2,2 };

int parent[100001];
ll cost[100001];
Vi root[100001];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
		cost[a] += cost[b];
	}
}
iii edge[100000];
int main() {
	MEM_1(parent);
	int n, m, p, q;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	fup(i, 0, m - 1, 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		merge(x, y);
		edge[i] = iii(x, y, z);
	}
	fup(i, 0, m - 1, 1)
	{
		int x, y, z;
		tie(x, y, z) = edge[i];
		cost[find(x)] += z;
	}
	VPll ans;
	priority_queue<Pll, VPll, greater<Pll> > pq;
	int cnt = 0;
	fup(i, 1, n, 1)
	{
		if (parent[i] < 0)
		{
			if (cost[i] > (ll)1e9)cost[i] = (ll)1e9;
			cnt++;
			pq.push(mp(cost[i], i));
		}
	}
	if (cnt < q)return !printf("NO");
	while (pq.size() > 1 && p > 0 && cnt > q)
	{
		ll c1, x1, c2, x2;
		tie(c1, x1) = pq.top();
		pq.pop();
		tie(c2, x2) = pq.top();
		pq.pop();
		merge(x1, x2);
		ans.push_back(mp(x1, x2));
		cost[x1] += c1 + c2 + 1;
		if (cost[x1] > (ll)1e9)cost[x1] = (ll)1e9;
		pq.push(mp(cost[x1], x1));
		p--, cnt--;
	}
	if (p > 0 && q == n)return !printf("NO");
	if (p == 0 && q != cnt)return !printf("NO");
	puts("YES");
	fup(i, 1, n, 1)root[find(i)].push_back(i);
	fup(i, 1, n, 1)
	{
		if (root[i].size() > 1)
		{
			while (p--)
			{
				ans.push_back(mp(root[i][0], root[i][1]));
			}
			break;
		}
	}
	for (const auto &p : ans)
		printf("%lld %lld\n", p.X, p.Y);
}