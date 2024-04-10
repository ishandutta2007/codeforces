#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

bool a = false, b = false;
int l = 0;

void dfs(int vertex, int last, int d) {
	if (data[vertex].size() == 1) {
		if (d%2) a=true;
		else b = true;
	}

	int cnt = 0;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		if (data[to].size() == 1) {
			cnt++;
			//add = false;
		}
		dfs(to, vertex, d+1);
	}

	l += max(0, cnt-1);
}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	data.assign(n, {});
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v), data[v].push_back(u);
	}

	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (data[i].size() > 1) root = i;
	}

	dfs(root, -1, 0);
	if (a&&b) cout << "3 ";
	else cout << "1 ";

	cout << n-1-l << "\n";

}