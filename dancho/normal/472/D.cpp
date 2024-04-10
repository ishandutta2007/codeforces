#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct el
{
	el() {}
	el(int _l, int _a, int _b)
	{
		l = _l; a = _a; b = _b;
	}

	int l, a, b;
	bool operator<(const el& e) const
	{
		return l < e.l;
	}

};

int n;
bool us[2048][2048];
int d[2048][2048];

vector<el> e;

int par[2048];

int ufind(int v)
{
	if (par[v] == -1)
		return v;
	return (par[v] = ufind(par[v]));
}

vector<int> con[2048];

int main()
{
	memset(us, 0, sizeof(us));
		scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &d[i][j]);
			if (i != j)
				e.push_back(el(d[i][j], i, j));
		}
		if (d[i][i] != 0)
		{
			printf("NO\n");
			return 0;
		}
		us[i][i] = 1;
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (d[i][j] != d[j][i])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	
	sort(e.begin(), e.end());
	
	memset(par, -1, sizeof(par));
	for (int i = 0; i < n; ++i)
		con[i].push_back(i);
	
	for (int i = 0; i < (int) e.size(); ++i)
	{
		int l = e[i].l;
		int a = e[i].a;
		int b = e[i].b;
		//~ printf("EL %d %d %d\n", l, a, b);
		if (l == 0)
		{
			printf("NO\n");
			return 0;
		}
		if (us[a][b])
			continue;
		int pa = ufind(a);
		int pb = ufind(b);
		//~ printf("PA %d %d : %d %d\n", pa, (int) con[pa].size(), pb, (int) con[pb].size());
		for (int j = 0; j < (int) con[pa].size(); ++j)
		{
			for (int k = 0; k < (int) con[pb].size(); ++k)
			{
				int ua = con[pa][j];
				int ub = con[pb][k];
				if (!us[ua][a] || !us[ub][b])
				{
					printf("NO\n");
					return 0;
				}
				
				if (d[ua][a] + d[ub][b] + l != d[ua][ub])
				{
					printf("NO\n");
					return 0;
				}
				//~ printf("US %d %d\n", ua, ub);
				us[ua][ub] = us[ub][ua] = 1;
			}
		}
		par[pa] = pb;
		con[pb].insert(con[pb].end(), con[pa].begin(), con[pa].end());
		con[pa].clear();
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j && !us[i][j])
			{
				//~ printf("%d %d\n", i, j);
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");
	return 0;
}