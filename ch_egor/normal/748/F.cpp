/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define ppb pop_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < n; i++)

const int MX = 228228;

int n, k;
vector<int> g[MX];
int arr[MX];
int sz[MX];
bool nn[MX];
int mx_sz[MX];
vector<int> now;
vector<int> tt;

void dfs(int v, int p = -1)
{
	mx_sz[v] = 0;
	for (int i = 0; i < sz(g[v]); ++i)
	{
		int u = g[v][i];
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
		mx_sz[v] = max(mx_sz[v], sz[u]);
	}
}

bool zaebis(int v)
{
	return k >= 2 * mx_sz[v] && k >= 2 * (sz[0] - sz[v]);
}

void dfs1(int v, vector<int> &gg, int p)
{
	if (nn[v]) gg.pb(v);
	for (int i = 0; i < sz(g[v]); ++i)
	{
		int u = g[v][i];
		if (u == p) continue;
		dfs1(u, gg, v);
	}
}

int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	k += k;
	for (int i = 0; i < n - 1; ++i)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		--v; --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	memset(sz, 0, sizeof(sz));
	for (int i = 0; i < k; ++i)
	{
		int p;
		scanf("%d", &p);
		--p;
		nn[p]= 1;
		sz[p] = 1;
	}
	
	dfs(0);

	printf("1\n");
	for (int i = 0; i < n; ++i)
	{
		if (zaebis(i))
		{
			printf("%d\n", i + 1);
			vector<vector<int>> cc;
			set<pii> kk;
			for (int j = 0; j < sz(g[i]); ++j)
			{
				cc.resize(sz(cc) + 1);
				dfs1(g[i][j], cc.back(), i);
			}
			if (nn[i]) cc.push_back(vector<int>(1, i));
			for (int i = 0; i < sz(cc); ++i)
			{
				kk.insert(mp(sz(cc[i]), i));
			}
			while (!kk.empty())
			{
				auto it = kk.end();
				--it;
				if (it->first == 0) return 0;
				pii c1 = *it;
				--it;
				pii c2 = *it;
				kk.erase(c1);
				kk.erase(c2);
				printf("%d %d %d\n", cc[c1.second].back() + 1, cc[c2.second].back() + 1, i + 1);
				cc[c1.second].ppb();
				cc[c2.second].ppb();
				if (c1.first > 1)
				{
					--c1.first;
					kk.insert(c1);
				}
				if (c2.first > 1)
				{
					--c2.first;
					kk.insert(c2);
				}
			}
			return 0;
		}
	}
}