#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m;

void it_upd(long long it[], int pos, long long val)
{
	for (int i = pos; i <= n; i += (i&(-i)))
	{
		it[i] += val;
	}
}

long long it_get(long long it[], int pos)
{
	int res = 0;
	for (int i = pos; i > 0; i -= (i&(-i)))
	{
		res += it[i];
	}
	return res;
}

vector<int> g[1<<20];
long long odd[1<<20], even[1<<20];

int st[1<<20], en[1<<20];
int no[1<<20], ln;
int dep[1<<20];
int a[1<<20];

void dfs(int v)
{
	st[v] = no[v] = ++ln;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int u = g[v][i];
		if (dep[u] == -1)
		{
			dep[u] = dep[v] + 1;
			dfs(u);
		}
	}
	
	en[v] = ln;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i+1]);
	}
	
	for (int i = 0; i < n-1; ++i)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}
	
	memset(dep, -1, sizeof(dep));
	ln = 0;
	dep[1] = 0;
	dfs(1);
	
	memset(odd, 0, sizeof(odd));
	memset(even, 0, sizeof(even));
	int t, x, val;
	//~ for (int i = 1; i <= n; i++)
	//~ {
		//~ printf("A %d %d %d\n", i, st[i], en[i]);
	//~ }
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d %d", &x, &val);
			if (dep[x]&1)
			{
				it_upd(odd, st[x], val);
				it_upd(odd, en[x]+1, -val);
			}
			else
			{
				it_upd(even, st[x], val);
				it_upd(even, en[x]+1, -val);
			}
		}
		else
		{
			scanf("%d", &x);
			long long ans = a[x];
			if (dep[x]&1)
			{
				ans = ans + it_get(odd, st[x]) - it_get(even, st[x]);
			}
			else
			{
				ans = ans + it_get(even, st[x]) - it_get(odd, st[x]);
			}
			//~ printf("AA %d %d %d : %d %d\n", x, (int) a[x], (int) ans, (int) it_get(even, st[x]), (int) it_get(odd, st[x]));
			printf("%I64d\n", ans);
		}
	}
	
	return 0;
}