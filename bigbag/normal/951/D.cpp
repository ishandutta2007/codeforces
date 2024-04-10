#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;
const int max_n = -1, inf = 1000111222;

const int MAX = 500500;
const int LEN = 20;

struct DSU
{
	int P[MAX];
	int H[MAX];

	void init(int n)
	{
		FOR (i, 0, n)
		{
			P[i] = i;
			H[i] = 1;
		}
	}

	int find(int x)
	{
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (x == y) return;

		if (H[x] > H[y]) swap(x, y);

		P[x] = y;
		H[y] += H[x];
	}
} D;

VI g[MAX];
int UP[MAX][LEN];
int tin[MAX];
int tout[MAX];
int timer = 0;

vector<pair<int, PII> > E;

VI ADD[MAX];
VI DEL[MAX];

void dfs(int x, int p)
{
	tin[x] = timer++;

	UP[x][0] = p;
	FOR (i, 1, LEN)
	{
		UP[x][i] = UP[UP[x][i-1]][i-1];
	}

	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (to == p) continue;

		dfs(to, x);
	}

	tout[x] = timer++;
}

bool isUpper(int x, int y)
{
	if (tin[x] <= tin[y] && tout[x] >= tout[y]) return true;
	return false;
}

int lca(int x, int y)
{
	if (isUpper(x, y)) return x;

	RFOR(i, LEN, 0)
	{
		if (!isUpper(UP[x][i], y)) x = UP[x][i];
	}

	return UP[x][0];
}

LL res = 0;

multiset<int> S[MAX];
int I[MAX];
int sz = 0;

void add(int x, int to)
{
	FOR (i, 0, SZ(ADD[x]))
	{
		S[to].insert(ADD[x][i]);
	}
}

void remove(int x, int from)
{
	FOR (i, 0, SZ(DEL[x]))
	{
		S[from].erase(S[from].find(DEL[x][i]));
		S[from].erase(S[from].find(DEL[x][i]));
	}
}

void cpy(int from, int to)
{
	ITER(it, S[from])
	{
		S[to].insert(*it);
	}
}


void dfs2(int x, int p)
{
	if (p != -1 && SZ(g[x]) == 1)
	{
		I[x] = sz++;
		add(x, I[x]);
		return;
	}

	PII mx = MP(-INF, -INF);

	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (to == p) continue;
		dfs2(to, x);


		int wh = I[to];


//		cout<<"!! "<<x<<' '<<to<<": "<<SZ(S[wh])<<endl;


		if (S[wh].empty())
		{
			cout<<-1<<endl;
			exit(0);
		}

		res += *S[wh].begin();

		mx = max(mx, MP(SZ(S[wh]), to));
	}

	int y = mx.second;


	I[x] = I[y];


	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (to == p) continue;
		if (to == y) continue;

		cpy(I[to], I[x]);
	}

	add(x, I[x]);
	remove(x, I[x]);
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(0);

	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	D.init(n);
	FOR (i, 0, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		D.unite(x, y);

		g[x].PB(y);
		g[y].PB(x);
	}

	FOR (i, 0, m)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;

		E.PB(MP(c, MP(x, y)));

		if (D.find(x) != D.find(y))
		{
			g[x].PB(y);
			g[y].PB(x);
			res -= c;
			D.unite(x, y);
		}
	}

	dfs(0, 0);



	FOR (i, 0, m)
	{
		int x = E[i].second.first;
		int y = E[i].second.second;
		int c = E[i].first;

		ADD[x].PB(c);
		ADD[y].PB(c);

		int z = lca(x, y);

		DEL[z].PB(c);
	}


	dfs2(0, -1);


	cout<<res<<endl;
	return 0;
}