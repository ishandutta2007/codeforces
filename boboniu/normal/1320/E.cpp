#include <bits/stdc++.h>

#define NS (400005)
#define LGS (19)

using namespace std;

typedef long long LL;

template <typename _Tp>
inline void IN(_Tp &dig)
{
	char c;
	bool flag = 0;
	dig = 0;
	while (c = getchar(), !isdigit(c))
		if (c == '-')
			flag = 1;
	while (isdigit(c))
		dig = dig * 10 + c - '0', c = getchar();
	if (flag)
		dig = -dig;
}

struct graph
{
	int head[NS], nxt[NS << 1], to[NS << 1], w[NS << 1], sz;
	void init() { memset(head, -1, sizeof(head)), sz = 0; }
	graph() { init(); }
	void push(int a, int b, int c)
	{
		nxt[sz] = head[a], to[sz] = b, w[sz] = c, head[a] = sz++;
	}
	int &operator[](const int a) { return to[a]; }
} g;

int n, pre[NS][LGS + 1], dep[NS], mx[NS][LGS + 1], id[NS], dfn;

int m, k, h[NS], sta[NS], top, MX;

int speed[NS];

LL f[NS];

int book[NS];

void Init(int a, int fa)
{
	pre[a][0] = fa, dep[a] = dep[fa] + 1, id[a] = ++dfn;
	for (int i = 1; i <= LGS; i += 1)
	{
		pre[a][i] = pre[pre[a][i - 1]][i - 1];
	}
	for (int i = g.head[a]; ~i; i = g.nxt[i])
		if (g[i] != fa)
			Init(g[i], a);
}

int lca(int a, int b)
{
	MX = dep[a] + dep[b];
	if (dep[a] > dep[b])
		swap(a, b);
	for (int i = LGS; i >= 0; i -= 1)
		if (dep[pre[b][i]] >= dep[a])
			b = pre[b][i];
	if (a == b)
	{
		MX -= 2 * dep[a];
		return a;
	}
	for (int i = LGS; i >= 0; i -= 1)
		if (pre[a][i] != pre[b][i])
		{
			a = pre[a][i], b = pre[b][i];
		}
	MX -= 2 * dep[pre[a][0]];
	return pre[a][0];
}

bool cmp(int a, int b) { return id[a] < id[b]; }

vector<int> v;
vector<array<int, 2>> adj[NS];
int aff[NS], lab[NS], ph[NS];

void Dfs(int a)
{
	v.push_back(a);
	adj[a].clear();
	for (int i = g.head[a]; ~i; i = g.nxt[i])
	{
		Dfs(g[i]);
	}
}

int main(int argc, char const *argv[])
{
	IN(n);
	for (int i = 1, a, b, c; i < n; i += 1)
		IN(a), IN(b), g.push(a, b, 1), g.push(b, a, 1);
	Init(1, 0), IN(m);
	while (m--)
	{
		//cout << "ANSWER" << endl;
		int k1, k2;
		IN(k1);
		IN(k2);
		k = k1;
		for (int i = 1; i <= k1; i += 1)
		{
			IN(h[i]), book[h[i]] = 1;
			lab[h[i]] = i;
			IN(speed[i]);
		}
		for (int i = 1; i <= k2; i += 1)
		{
			IN(ph[i]);
		}
		for (int i = 1; i <= k2; i++)
		{
			if (!book[ph[i]])
				h[++k] = ph[i];
		}
		sort(h + 1, h + 1 + k, cmp);
		sta[top = 1] = 1, g.sz = 0, g.head[1] = -1;
		for (int i = 1, l; i <= k; i += 1)
			if (h[i] != 1)
			{
				l = lca(sta[top], h[i]);
				if (l != sta[top])
				{
					while (id[l] < id[sta[top - 1]])
					{
						lca(sta[top - 1], sta[top]);
						g.push(sta[top - 1], sta[top], MX);
						top--;
					}
					if (id[l] > id[sta[top - 1]])
					{
						g.head[l] = -1, lca(l, sta[top]);
						g.push(l, sta[top], MX), sta[top] = l;
					}
					else
						lca(l, sta[top]), g.push(l, sta[top--], MX);
				}
				g.head[h[i]] = -1, sta[++top] = h[i];
			}
		for (int i = 1; i < top; i += 1)
			lca(sta[i], sta[i + 1]), g.push(sta[i], sta[i + 1], MX);
		v.clear();
		Dfs(1);
		for (auto a : v)
		{
			for (int i = g.head[a]; ~i; i = g.nxt[i])
			{
				adj[a].push_back({g[i], g.w[i]});
				adj[g[i]].push_back({a, g.w[i]});
			}
		}
		priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> q; // time, id, c, length
		for (auto a : v)
		{
			aff[a] = -1;
			if (book[a])
			{
				q.push({0, lab[a], a, 0});
			}
		}
		while (!q.empty())
		{
			auto p = q.top();
			q.pop();
			int a = p[2];
			if (aff[a] != -1)
				continue;
			aff[a] = p[1];
			for (auto c : adj[a])
			{
				q.push({(p[3] + c[1] + speed[p[1]] - 1) / speed[p[1]], p[1], c[0], p[3] + c[1]});
			}
		}
		for (int i = 1; i <= k; i += 1)
			book[h[i]] = 0;
		for (int i = 1; i <= k2; i += 1)
		{
			cout << aff[ph[i]] << " ";
			assert(aff[ph[i]] != -1);
		}
		cout << "\n";
	}
	return 0;
}