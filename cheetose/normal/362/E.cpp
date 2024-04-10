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
#define INF 987654321
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
const int MOD = 5000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 2,2,-2,-2 }, DY[] = { 2,-2,-2,2 };

int a[51][51];
const int S = 0, T = 51;
int n, k;
struct Edge {
	int to, r, c;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R, int C)
	{
		to = T, r = R, c = C;
	}
};
vector<Edge *> v[52];
void addedge(int f, int t, int r, int c)
{
	Edge* ori = new Edge(t, r, c);
	Edge* rev = new Edge(f, 0, -c);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
bool inQ[52];
int dist[52];
Pi p[52];
bool ok(int m)
{
	fup(i, 0, 51, 1)v[i].clear();
	fup(i,1,n,1)
		fup(j, 1, n, 1)
	{
		if (a[i][j] > 0)
		{
			addedge(i, j, a[i][j], 0);
			addedge(i, j, 3000, 1);
		}
	}
	addedge(S, 1, INF, 0);
	addedge(n, T, m, 0);
	int ans = 0, fl = 0;
	while (1)
	{
		MEM0(inQ);
		fill(dist, dist + 52, INF);
		fill(p, p + 52, Pi(-1, -1));
		queue<int> q;
		q.push(S);
		dist[S] = 0;
		inQ[S] = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			inQ[x] = 0;
			for (int i = 0; i < v[x].size(); i++)
			{
				int next = v[x][i]->to;
				if (dist[next]>dist[x] + v[x][i]->c && v[x][i]->r > 0)
				{
					dist[next] = dist[x] + v[x][i]->c;
					p[next] = Pi(x, i);
					if (!inQ[next])
					{
						q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
		if (p[T].X == -1)break;
		int flow = INF;
		for (int i = T; i != S; i = p[i].X)
		{
			flow = min(flow, v[p[i].X][p[i].Y]->r);
		}
		fl += flow;
		for (int i = T; i != S; i = p[i].first)
		{
			v[p[i].X][p[i].Y]->r -= flow;
			v[p[i].X][p[i].Y]->rev->r += flow;
			ans += v[p[i].X][p[i].Y]->c * flow;
		}
	}
	return ans <= k && fl==m;
}
int main() {
	scanf("%d%d", &n, &k);
	fup(i, 1, n, 1)fup(j, 1, n, 1)scanf("%d", a[i] + j);
	int l = 0, r = INF;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (ok(m))l = m + 1;
		else r = m - 1;
	}
	printf("%d", r);
}