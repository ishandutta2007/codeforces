#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int us[1<<20];
vector<int> g[1<<20];

int go[1<<20], in[1<<20];

int ans = 0;
vector<int> sl;

void dfs(int v, int fc = 0, int fn = 0)
{
	if (us[v])
		return;
	us[v] = 1;

	if (fc)
		in[v] = 1 - in[v];

	int nfc, nfn;
	nfc = fn;
	nfn = fc;
	if (in[v] != go[v])
	{
		++ans;
		sl.push_back(v);
		//flip v;

		nfn = 1 - nfn;
	}
	for (int i = 0; i < (int) g[v].size(); ++i)
	{
		int u = g[v][i];
		dfs(u, nfc, nfn);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &go[i]);
	}

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &in[i]);
	}

	memset(us, 0, sizeof(us));
	dfs(1);

	printf("%d\n", ans);
	for (int i = 0; i < (int) sl.size(); ++i)
		printf("%d\n", sl[i]);
	return 0;
}