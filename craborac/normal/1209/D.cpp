#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int> mas[(int)1e5 + 10];
int used[(int)1e5 + 10];

void dfs(int v)
{
	used[v] = 1;
	for (int u: mas[v])
	{
		if (used[u] == 0)
		{
			ans++;
			dfs(u);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	mas[a].push_back(b);
    	mas[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    	if (used[i] == 0)
    		dfs(i);
    cout << m - ans << endl;
    return 0;
}