#include <algorithm>
#include <cstdio>
#include <set>
int fa[100005], ans[100005], lab[100005], mxd[100005];
struct comper
{
	inline bool operator ()(int x, int y) const
	{ return mxd[x] == mxd[y] ? x < y : mxd[x] > mxd[y]; }
};
std::set<int, comper> son[100005];
int main()
{
	// freopen("1246D.in", "r", stdin);
	int n, rt = 0, len = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d", fa + i);
	for (int i = n - 1; i; i--)
	{
		mxd[fa[i]] = std::max(mxd[fa[i]], mxd[i] + 1);
		son[fa[i]].insert(i);
	}
	lab[len++] = rt;
	while (!son[rt].empty())
	{
		if (son[rt].size() == 1)
		{
			rt = *son[rt].begin();
			lab[len++] = rt;
			continue;
		}
		int u = *son[rt].rbegin(), v = *son[rt].begin();
		son[rt].erase(u);
		son[rt].erase(v);
		mxd[u] = std::max(mxd[u], mxd[v] + 1);
		son[u].insert(v);
		son[rt].insert(u);
		ans[cnt++] = v;
	}
	for (int i = 0; i < len; i++)
		printf("%d%c", lab[i], " \n"[i + 1 == len]);
	printf("%d\n", cnt);
	for (int i = cnt - 1; i >= 0; i--)
		printf("%d%c", ans[i], " \n"[!i]);
	return 0;
}