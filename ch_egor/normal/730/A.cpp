/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[107];
int gg[107];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	vector<vector<int> > res;
	for (; ; )
	{
		bool ok = true;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] != a[1])
			{
				ok = false;
			}
		}
		if (ok)
		{
			break;
		}
		vector<pair<int, int> >go;
		for (int j = 1; j <= n; j++)
		{
			go.push_back(make_pair(a[j], j));
		}
		sort(go.rbegin(), go.rend());
		int goEq = 0;
		for (int j = 0; j < (int)go.size(); j++)
		{
			if (go[j].first == go[0].first) goEq++;
		}
		if (goEq == 1 || goEq % 2 == 0)
		{
			res.push_back({go[0].second, go[1].second});
		}
		else
		{
			res.push_back({go[0].second, go[1].second, go[2].second});
		}
		for (int j = 0; j < (int)res.back().size(); j++)
		{
			int pos = res.back()[j];
			a[pos] = max(0, a[pos] - 1);
		}
	}
	printf("%d\n", a[1]);
	printf("%d\n", res.size());
	for (int i = 0; i < (int)res.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			gg[j] = 0;
		}
		for (int j = 0; j < (int)res[i].size(); j++)
		{
			gg[res[i][j]] = 1;
		}
		for (int j = 1; j <= n; j++)
		{
			printf("%d", gg[j]);
		}
		printf("\n");
	}
}