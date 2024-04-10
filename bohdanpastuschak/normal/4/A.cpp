#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

namespace Math
{
	inline LL Random(LL n)
	{
		return (abs(rand() << 13) ^ rand()) % n;
	}

	inline LL gcd(LL x, LL y)
	{
		if (!y)
			return x;

		return gcd(y, x % y);
	}

	inline LL mult(LL x, LL y, LL m)
	{
		return (x * y) % m;
	}

	inline LL add(LL x, LL y, LL m)
	{
		if (x + y < m)
			return x + y;
		else
			return x + y - m;
	}

	inline LL power(LL x, LL y, LL m)
	{
		LL r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}

		return r;
	}

	bool MillerRabin(LL n, int k)
	{
		if (n <= 3)
			return n > 1;

		LL d = n - 1;
		int s = 0;
		while(d % 2 == 0)
		{
			d >>= 1;
			++s;
		}

		FOR(iter, 0, k)
		{
			LL a = Random(n - 3) + 2;
			LL x = power(a, d, n);
			if (x == 1 || x == n - 1)
				continue;

			cout << "pered cyclom" << endl;
			bool ok = 0;
			FOR(i, 0, s - 1)
			{
				x = mult(x, x, n);
				if (x == 1)
					return 0;

				if (x == n - 1)
				{
					ok = 1;
					break;
				}
			}

			cout << "suka" << endl;
			if (!ok)
				return 0;
			cout << "tuta" << endl;
		}

		return 1;
	}

	LL pollard(LL n)
	{
		if (n % 2 == 0)
			return 2;

		LL x = Random(n - 2) + 2;
		LL c = Random(n - 1) + 1;
		LL y = x, d = 1;

		while(d == 1)
		{
			x = add(mult(x, x, n), c, n);
			y = add(mult(y, y, n), c, n);
			y = add(mult(y, y, n), c, n);
			if (x == y)
				return pollard(n);

			d = gcd(abs(x - y), n);
		}

		return d;
	}
};

namespace MaxFlow
{
	const int MAX = 1 << 20;

	struct edge
	{
		int from;
		int to;
		int cap;
		int flow;
	};

	int n;
	int source;
	int sink;
	int d[MAX];
	int ptr[MAX];
	vector<edge> e;
	VI g[MAX];

	void add(int u, int v, int w)
	{
		g[u].push_back(SZ(e));
		e.PB({ u, v, w, 0 });
		g[v].push_back(SZ(e));
		e.PB({v, u, 0, 0});
	}

	bool bfs()
	{
		queue<int> q;
		q.push(source);
		FOR(i, 0, n)
			d[i] = -1;

		d[source] = 0;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (auto i : g[v])
			{
				int to = e[i].to;
				if (d[to] != -1)
					continue;

				if (e[i].flow == e[i].cap)
					continue;

				q.push(to);
				d[to] = d[v] + 1;
			}
		}

		return d[sink] != -1;
	}

	int dfs(int v, int flow)
	{
		if (!flow)
			return 0;

		if (v == sink)
			return flow;

		while (1)
		{
			if (ptr[v] == SZ(g[v]))
				break;

			int id = g[v][ptr[v]];
			int to = e[id].to;

			if (d[to] != d[v] + 1)
			{
				++ptr[v];
				continue;
			}

			int push = dfs(to, min(flow, e[id].cap - e[id].flow));
			if (push == 0)
			{
				++ptr[v];
				continue;
			}

			e[id].flow += push;
			e[id ^ 1].flow -= push;
			return push;
		}

		return 0;
	}

	int dinic()
	{
		cerr << "Don't forget about constant: " << MAX << endl;
		LL flow = 0;
		while (1)
		{
			if (!bfs())
				break;

			FOR(i, 0, n)
				ptr[i] = 0;

			while (int push = dfs(source, INF))
				flow += push;
		}

		return flow;
	}
};

namespace MinCostMaxFlow
{
	const int MAX = 1 << 20;

	struct edge
	{
		int x, y;
		int cap, flow;
		LL price;
	};

	int n;
	int source;
	int sink;
	vector<edge> E;
	VI g[MAX];
	char used[MAX];
	LL d[MAX];
	int parent[MAX];

	void add(int x, int y, int cap, LL price)
	{
		g[x].PB(SZ(E));
		E.PB({x, y, cap, 0, price});
		g[y].PB(SZ(E));
		E.PB({y, x, 0, 0, -price});
	}

	void clear()
	{
		E.clear();
		FOR(i, 0, n)
			g[i].clear();
	}

	pair<int, LL> Flow()
	{
		int flow = 0;
		LL price = 0;

		while(1)
		{
			FOR(i, 0, n)
			{
				d[i] = LINF;
				parent[i] = -1;
				used[i] = 0;
			}

			deque<int> q;
			q.PB(source);

			d[source] = 0;

			while(!q.empty())
			{
				int v = q.front();
				q.pop_front();
				used[v] = 1;

				FOR(i, 0, SZ(g[v]))
				{
					int e = g[v][i];
					if (E[e].cap == E[e].flow)
						continue;

					int to = E[e].y;
					LL len = E[e].price;

					if (d[to] > d[v] + len)
					{
						d[to] = d[v] + len;
						parent[to] = e;

						if (used[to] == 0)
							q.PB(to);
						else
							if (used[to] == 2)
								q.push_front(to);
					}
				}

				used[v] = 2;
			}

			if (parent[sink] == -1)
				break;


			int x = sink;
			int f = INF;
			LL p = 0;

			while(x != source)
			{
				int e = parent[x];
				f = min(f, E[e].cap - E[e].flow);
				p += E[e].price;
				x = E[e].x;
			}

			x = sink;
			while(x != source)
			{
				int e = parent[x];
				E[e].flow += f;
				E[e ^ 1].flow -= f;
				x = E[e].x;
			}

			flow += f;
			price += p * f;
		}

		return MP(flow, price);
	}
};

namespace FFT
{
	struct complex
	{
		double x, y;
		complex() { x = y = 0; }
		complex(double x, double y) : x(x), y(y) { }
	};

	inline complex operator+(complex a, complex b) { return complex(a.x + b.x, a.y + b.y); }
	inline complex operator-(complex a, complex b) { return complex(a.x - b.x, a.y - b.y); }
	inline complex operator*(complex a, complex b) { return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline complex conj(complex a) { return complex(a.x, -a.y); }

	int base = 1;
	vector<complex> roots = { { 0, 0 },{ 1, 0 } };
	vector<int> rev = { 0, 1 };

	void ensure_base(int nbase)
	{
		if (nbase <= base)
			return;

		rev.resize(1 << nbase);
		FOR(i, 0, 1 << nbase)
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

		roots.resize(1 << nbase);
		while (base < nbase)
		{
			double angle = 2.0 * PI / (1 << (base + 1));
			FOR(i, 1 << (base - 1), 1 << base)
			{
				roots[i << 1] = roots[i];
				double angle_i = angle * (2 * i + 1 - (1 << base));
				roots[(i << 1) + 1] = complex(cos(angle_i), sin(angle_i));
			}

			base++;
		}
	}

	void fft(vector<complex>& a, int n = -1)
	{
		if (n == -1)
			n = a.size();

		int zeros = __builtin_ctz(n);
		ensure_base(zeros);

		int shift = base - zeros;
		FOR(i, 0, n)
			if (i < (rev[i] >> shift))
				swap(a[i], a[rev[i] >> shift]);

		for (int k = 1; k < n; k <<= 1)
		{
			for (int i = 0; i < n; i += 2 * k)
			{
				FOR(j, 0, k)
				{
					complex z = a[i + j + k] * roots[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	vector<complex> fa, fb;

	void multiply(VI&a, VI&b, VI& res)
	{
		int need = SZ(a) + SZ(b) - 1;
		int nbase = 0;

		while ((1 << nbase) < need)
			nbase++;

		ensure_base(nbase);
		int sz = 1 << nbase;

		if (sz > SZ(fa))
			fa.resize(sz);

		FOR(i, 0, sz)
		{
			int x = (i < SZ(a) ? a[i] : 0);
			int y = (i < SZ(b) ? b[i] : 0);
			fa[i] = complex(x, y);
		}

		fft(fa, sz);
		complex r(0, -0.25 / sz);
		FOR(i, 0, (sz >> 1) + 1)
		{
			int j = (sz - i) & (sz - 1);
			complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
			if (i != j)
				fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;

			fa[i] = z;
		}

		fft(fa, sz);
		res.resize(need);
		FOR(i, 0, need)
			if (fa[i].x > 0)
				res[i] = fa[i].x + 0.5;
			else
				res[i] = fa[i].x - 0.5;
	}
};

namespace Strings
{
	VI prefix_function(string& s)
	{
		int n = SZ(s);
		VI pi(n, 0);

		FOR(i, 1, n)
		{
			int j = pi[i - 1];

			while(j > 0 && s[i] != s[j])
				j = pi[j - 1];

			if (s[i] == s[j])
				++j;

			pi[i] = j;
		}

		return pi;
	}

	VI z_function(string& s)
	{
		int n = SZ(s);
		VI z(n, 0);
		int l = 0, r = 0;

		FOR(i, 1, n)
		{
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);

			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];

			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}

		return z;
	}

	VI manacher_odd(string& s)
	{
		int n = SZ(s);
		VI d(n, 0);
		int l = 0, r = -1, k;

		FOR(i, 0, n)
		{
			if(i > r)
				k = 1;
			else
				k = min(d[l + r - i], r - i);

			while(i >= k && i + k < n && s[i - k] == s[i + k])
				++k;

			d[i] = k;

			if(i + k - 1 > r)
				l = i - k + 1, r = i + k - 1;
		}

		return d;
	}

	VI manacher_even(string& s)
	{
		int n = SZ(s);
		VI d(n, 0);
		int l = 0, r = -1, k;

		FOR(i, 0, n)
		{
			if(i > r)
				k = 0;
			else
				k = min(d[l + r - i + 1], r - i + 1);

			while(i >= k + 1 && i + k < n && s[i + k] == s[i - k - 1])
				++k;

			d[i] = k;

			if (i + k - 1 > r)
				l = i - k, r = i + k - 1;
		}

		return d;
	}

};

namespace Treap
{
	const int MAX = 1 << 20;

	struct node
	{
		int l;
		int r;
		int y;
		int cnt;
	};

	node a[MAX];

	int getCnt(int v)
	{
		if (v == -1)
			return 0;

		int res = 1;
		if (a[v].l != -1)
			res += a[a[v].l].cnt;

		if (a[v].r != -1)
			res += a[a[v].r].cnt;

		return res;
	}

	void upd(int v)
	{
		if (v == -1)
			return;

		a[v].cnt = getCnt(v);
	}

	int merge(int x, int y)
	{
		if (x == -1)
			return y;
		if (y == -1)
			return x;

		int res;
		if (a[x].y > a[y].y)
		{
			res = merge(a[x].r, y);
			a[x].r = res;
			res = x;
		}
		else
		{
			res = merge(x, a[y].l);
			a[y].l = res;
			res = y;
		}

		upd(res);
		return res;
	}

	PII split(int v, int c)
	{
		if (v == -1)
			return MP(-1, -1);

		if (c == 0)
			return MP(-1, v);

		PII res;
		int left = getCnt(a[v].l);

		if (left >= c)
		{
			res = split(a[v].l, c);
			a[v].l = res.second;
			res.second = v;
		}
		else
		{
			res = split(a[v].r, c - left - 1);
			a[v].r = res.first;
			res.first = v;
		}

		upd(v);
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	int n;
	cin >> n;
	if (n >= 4 && n % 2 == 0) cout << "YES";
	else cout << "NO";

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}