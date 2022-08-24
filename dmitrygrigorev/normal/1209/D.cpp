#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

vector<vector<int> > data;
vector<bool> used;
int cnt;
void dfs(int vertex){
	cnt++;
	used[vertex] = true;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (used[to]) continue;
		dfs(to);
	}
}

int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	data.assign(n, {});
	for (int i=0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}
	used.assign(n, false);
	int ans = 0;
	for (int i=0;i<n;++i){
		if (used[i]) continue;
		cnt=0;
		dfs(i);
		ans += cnt-1;
	}
	cout << m-ans;
}