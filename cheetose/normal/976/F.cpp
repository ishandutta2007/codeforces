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
ll MOD = 12345678910;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct Edge {
	int to, r, c, idx;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R, int C, int I)
	{
		to = T, r = R, c = C, idx = I;
	}
};
vector<Edge *> v[4002];
void addedge(int f, int t, int r, int c, int i)
{
	Edge* ori = new Edge(t, r, c, i);
	Edge* rev = new Edge(f, 0, -c, i);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
const int S = 4000, T = 4001;
int level[4002], work[4002];
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
				v[N][i]->r -= df;
				v[N][i]->rev->r += df;
				return df;
			}
		}
	}
	return 0;
}
Pi edge[2001];
int cnt[4000], c[4000];
bool chk[2001];
int main() {
	int n1, n2, m;
	scanf("%d%d%d", &n1, &n2, &m);
	fup(i, 0, n1 - 1, 1)addedge(S, i, 0, 0, -1);
	fup(i, n1, n1 + n2 - 1, 1)addedge(i, T, 0, 0, -1);
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		edge[i] = mp(x, n1+y);
		addedge(x, n1 + y, 1, 0, i);
		cnt[x]++;
		cnt[n1 + y]++;
	}
	int K = *min_element(cnt, cnt + n1 + n2);
	puts("0");
	fup(k, 1, K, 1)
	{
		for (auto &E : v[S])E->r++;
		for (auto &E : v[T])E->rev->r++;
		MEM0(c);
		MEM0(chk);
		while (bfs())
		{
			MEM0(work);
			while (1)
			{
				int f = dfs(S, T, INF);
				if (f == 0)break;
			}
		}
		Vi ans;
		fup(i, 0, n1 - 1, 1)
		{
			for (auto &E : v[i])
			{
				if (E->to != S && E->r == 0)
				{
					ans.push_back(E->idx);
					chk[E->idx] = 1;
					c[i]++, c[E->to]++;
				}
			}
		}
		fup(i, 0, n1 + n2 - 1, 1)
		{
			if (c[i] >= k)continue;
			for (auto &E : v[i])
			{
				if (chk[E->idx])continue;
				if (E->to != S && E->to != T)
				{
					ans.push_back(E->idx);
					chk[E->idx] = 1;
					c[i]++;
					if (c[i] == k)break;
				}
			}
		}
		printf("%d ", ans.size());
		for (int x : ans)printf("%d ", x);
		puts("");
	}
}