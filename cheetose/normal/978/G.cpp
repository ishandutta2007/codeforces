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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct Edge {
	int to, r, c;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R, int C)
	{
		to = T, r = R, c = C;
	}
};
vector<Edge *> v[205];
void addedge(int f, int t, int r, int c)
{
	Edge* ori = new Edge(t, r, c);
	Edge* rev = new Edge(f, 0, -c);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
const int S = 0, T = 204;
int level[205], work[205], parent[205];
bool bfs() {
	MEM_1(level);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto& nn : v[x]) {
			int next = nn->to;
			if (level[next] == -1 && nn->r > 0) {
				level[next] = level[x] + 1;
				q.push(next);
			}
		}
	}
	return level[T] != -1;
}
int dfs(int N, int des, int flow) {
	if (N == des) return flow;

	for (int &i = work[N]; i<v[N].size(); i++) {
		int next = v[N][i]->to;
		if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
			int df = dfs(next, des, min(v[N][i]->r, flow));
			if (df > 0) {
				parent[next] = N;
				v[N][i]->r -= df;
				v[N][i]->rev->r += df;
				return df;
			}
		}
	}
	return 0;
}
bool chk[101];
iii a[101];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fup(i, 1, n, 1)
		addedge(100 + i, T, 1, 0);
	int tot = 0;
	fup(i, 1, k, 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = iii(x, y, z);
		tot += z;
		chk[y] = 1;
	}
	fup(i, 1, k, 1)
	{
		int x, y, z;
		tie(x, y, z) = a[i];
		addedge(S, i, z, 0);
		fup(j, x, y - 1, 1)
			if (!chk[j])addedge(i, 100 + j, 1, 0);
	}
	int flow = 0;
	while (bfs())
	{
		MEM0(work);
		while (1)
		{
			int f = dfs(S, T, INF);
			if (f == 0)break;
			flow += f;
		}
	}
	if (flow != tot)return !printf("-1");
	fup(i, 101, 100 + n, 1)
	{
		if (chk[i - 100])printf("%d ", k + 1);
		else
		{
			printf("%d ", parent[i]);
		}
	}
}