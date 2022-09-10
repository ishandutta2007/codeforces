#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,avx")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
 
const double PI = acos(-1.0);
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 1 << 12;

struct Edge
{
	int to, cap, cost;
	Edge() {}
	Edge(int _to, int _cap, int _cost): to(_to), cap(_cap), cost(_cost) {}
};

int N;
vector<int> g[MAX];
vector<Edge> E;
int D[MAX], p[MAX], T[MAX];
int q1[MAX], q2[MAX];

void addEdge(int u, int v, int cap, int cost)
{
	g[u].push_back(SZ(E));
	E.push_back(Edge(v, cap, cost));
	g[v].push_back(SZ(E));
	E.push_back(Edge(u, 0, -cost));
}

int push(int s, int t)
{
	FOR(i, 0, N)
	{
		D[i] = INT_MAX;
		T[i] = 0;
	}
	D[s] = 0;
	T[s] = 1;
	q2[0] = s;
	int q1h = 0, q1t = 0, q2h = 0, q2t = 1;
	while(q1h != q1t || q2h != q2t)
	{
		int v;
		if(q1h != q1t)
		{
			v = q1[q1h++];
			if(q1h == N)
				q1h = 0;
		}
		else
			v = q2[q2h++];
		T[v] = 2;
		for(int id: g[v])
		{
			if(E[id].cap > 0)
			{
				int to = E[id].to, cost = E[id].cost;
				if(D[v] + cost < D[to])
				{
					D[to] = D[v] + cost;
					p[to] = id;
					if(T[to] == 2)
					{
						q1[q1t++] = to;
						if(q1t == N)
							q1t = 0;
					}
					else if(T[to] == 0)
					{
						q2[q2t++] = to;
					}
					T[to] = 1;
				}
			}
		}
	}
	int v = t, cost = 0;
	while(v != s)
	{
		E[p[v]].cap--;
		E[p[v] ^ 1].cap++;
		cost += E[p[v]].cost;
		v = E[p[v] ^ 1].to;
	}
	return cost;
}

int a[MAX];
vector<int> vec[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int d, n;
	cin >> d >> n;
	FOR(i, 0, n)
	{
		string str;
		cin >> str;
		reverse(ALL(str));
		for(char c: str)
			a[i] = 2 * a[i] + c - '0';
	}
	N = 2 * n + 3;
	int s = 2 * n + 1, t = 2 * n + 2;
	addEdge(2 * n, t, n, 0);
	FOR(i, 0, n)
	{
		addEdge(s, i, 1, 0);
		addEdge(n + i, t, 1, 0);
		addEdge(i, 2 * n, 1, __builtin_popcount(a[i]) + 1);
		FOR(j, 0, n)
			if(a[j] < a[i] && (a[i] & a[j]) == a[j])
				addEdge(i, n + j, 1, __builtin_popcount(a[i] ^ a[j]));
	}		
	int ans = -1;
	FOR(i, 0, n)
	{
		ans += push(s, t);
	}
	FOR(i, 0, n)
		for(int id: g[i])
			if(E[id].to >= n && E[id].to <= 2 * n && !E[id].cap)
			{
				vec[a[E[id].to - n]].push_back(a[i]);
			}
	cout << ans << endl;
	while(SZ(vec[0]))
	{
		int v = 0;
		while(SZ(vec[v]))
		{
			int from = vec[v].back();
			vec[v].pop_back();
			FOR(j, 0, d)
				if(((from ^ v) >> j) & 1)
					cout << j << " ";
			v = from;
		}
		if(SZ(vec[0]))
			cout << "R ";
	}
	cout << "\n";
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}