#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> g[100020];

double tot;
bool us[100020];

void dfs(int v, int dep)
{
	if (us[v])
		return;
	us[v] = 1;
	tot += 1.0 / dep;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int u = g[v][i];
		dfs(u, dep + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}

	memset(us, 0, sizeof(us));
	tot = 0;
	dfs(1, 1);
	printf("%.10lf\n", tot);
	return 0;
}