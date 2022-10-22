
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 300003;

int n, m, k;
vector <int> g[N], gr[N];
int to[N], from[N], mark[N], res[N], din[N], rem;
int x[N], r[N], y[N];

void out()
{
	cout << "-1\n";
	exit(0);
}

void dfs(int v)
{
	mark[v] = 1;
	for(int u : g[v])
		if(mark[u] == 1)
			out();
		else
		{
			if(!mark[u])
				dfs(u);
			from[v] = max(from[v], from[u]);
		}
	from[v]++;
	if(r[v] > 0)
	{
		if(from[v] > r[v])
			out();
		from[v] = r[v];
	}
	if(from[v] > k)
		out();
	mark[v] = 2;
}

bool seen[N];
set <pair<int, int>> ss, qs;

void updateRem()
{
	while(rem > 0 && seen[rem])
	{
		rem--;
		while(qs.size() && qs.rbegin()->first >= rem)
		{
			int v = qs.rbegin()->second;
			qs.erase({to[v], v});
			ss.insert({from[v], v});
		}
	}
}

void addSource(int v)
{
	int x = to[v];
	if(x >= rem)
		ss.insert({from[v], v});
	else
		qs.insert({x, v});
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		r[i] = in();
	for(int i = 0; i < m; i++)
	{
		x[i] = in() - 1;
		y[i] = in() - 1;
		g[x[i]].push_back(y[i]);
		gr[y[i]].push_back(x[i]);
		din[y[i]]++;
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	rem = k;
	fill(to, to + n, k);
	for(int i = 0; i < n; i++)
	{
		if(r[i] > 0)
			to[i] = min(to[i], r[i]);
		if(!din[i])
			addSource(i);
	}
	for(int i = 0; i < n; i++)
	{
		if(ss.empty())
			out();
		int v = ss.rbegin()->second;
		ss.erase({from[v], v});
		assert(to[v] >= rem);
		if(r[v] > 0)
			res[v] = r[v];
		else
			res[v] = max(rem, from[v]);
//		cerr << v << " : " << rem << " " << to[v] << ", " << from[v] << " -> " << res[v] << endl;
		seen[res[v]] = true;
		updateRem();
		for(int u : g[v])
		{
			din[u]--;
			to[u] = min(to[u], res[v] - 1);
			if(to[u] < from[u])
				out();
			if(din[u] == 0)
				addSource(u);
		}
	}
//	cerr << " -> " << rem << endl;
	if(rem != 0)
		out();
	for(int i = 0; i < m; i++)
		if(res[x[i]] <= res[y[i]])
			out();
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}