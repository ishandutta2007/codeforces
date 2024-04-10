#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<int> g[1<<20];
pii p[1<<20];

int s[1<<20];
vector< vector<int> > vs;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i].first);
		p[i].second = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}

	sort(p + 1, p + n + 1, greater<pii>());

	memset(s, -1, sizeof(s));
	double ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int v = p[i].second;
		int ls = -1;
		for (int j = 0; j < (int) g[v].size(); ++j)
		{
			int u = g[v][j];
			//~ printf("SS %d %d %d\n", v, u, s[u]);
			if (s[u] != -1)
			{
				if (ls == -1)
				{
					ls = s[u];
				}
				else if (ls != s[u])
				{
					int sa = ls;
					int sb = s[u];
					if (vs[sa].size() > vs[sb].size())
						swap(sa, sb);
					ans += (double) p[i].first * vs[sa].size() * vs[sb].size();
					//~ printf("MER %d %d %d\n", p[i].first, vs[sa].size(), vs[sb].size());
					for (int k = 0; k < (int) vs[sa].size(); ++k)
					{
						s[ vs[sa][k] ] = sb;
						vs[sb].push_back(vs[sa][k]);
					}
					vs[sa].clear();
					ls = sb;
				}
			}
		}
		if (ls != -1)
		{
			//~ printf("%d %lf _ %d %d : %d\n", v, ans, s[v], vs[ls].size(), ls);
			s[v] = ls;
			ans += (double) p[i].first * vs[s[v]].size();
			vs[ s[v] ].push_back(v);
		}
		else
		{
			s[v] = vs.size();
			vs.push_back(vector<int>());
			vs[s[v]].push_back(v);
		}
		//~ printf("%d %lf _ %d %d : %d\n", v, ans, s[v], vs[s[v]].size(), ls);
	}

	ans *= 2.0;
	ans = ans / n;
	ans = ans / (n-1);

	printf("%.8lf\n", ans);
	return 0;
}