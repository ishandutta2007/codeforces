/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int cmp(int a, int ida, int b, int idb)
{
	return make_pair(a, -ida) > make_pair(b, -idb);
}

int f(int a, int xa, int ida, int b, int xb, int idb)
{
	int ans = 0;
	ans += cmp(a, ida, b, idb) ^ cmp(a + xa, ida, b, idb);
	ans += cmp(a + xa, ida, b, idb) ^ cmp(a + xa, ida, b + xb, idb);

	return ans;
}
bool edge(int a, int xa, int ida, int b, int xb, int idb)
{
	int x1 = f(a, xa, ida, b, xb, idb);
	int x2 = f(b, xb, idb, a, xa, ida);
	return x1 == 2 && x2 == 0;
}

int n;
pair<int, int> arr[228];
vector<int> graph[228];
int used[228];


void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		int to = graph[v][i];
		if (used[to] == 1) assert(0);
		dfs(to);
	}
	used[v] = 2;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	int ans = 0;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (i != j)
			{
				if (edge(arr[i].first, arr[i].second, i, arr[j].first, arr[j].second, j))
				{
					ans += 2;
//					graph[i].push_back(j);
				}
				else if (edge(arr[j].first, arr[j].second, j, arr[i].first, arr[i].second, i))
				{
					ans += 2;
//					graph[j].push_back(i);
				}
				else
				{
					ans += f(arr[i].first, arr[i].second, i, arr[j].first, arr[j].second, j);
				}
			}
		}
	}

//	memset(used, 0, sizeof(used));

/*	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			dfs(i);
		}
	} */

	cout << ans;	
}