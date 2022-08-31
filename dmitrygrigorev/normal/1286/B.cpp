#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<int> c;
vector<int> ans;

int dfs(int vertex, int start) {
	int sz = 1;
	int cur = start;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		int Q = dfs(to, cur);
		cur += Q;
		sz += Q;
	}

	if (c[vertex] > sz - 1) {
		cout << "NO";
		exit(0);
	}

	ans[vertex] = start + c[vertex];
	for (int i = 0; i < ans.size(); ++i) {
		if (i==vertex) continue;
		if (ans[i] >= ans[vertex] && ans[i] < cur) ans[i]++;
	}

	return sz;

}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int root;

	int n;
	cin >> n;
	data.assign(n, {});
	ans.assign(n, -1);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		c.push_back(y);
		if (x == 0) root = i;
		else {
			x--;
			data[x].push_back(i);
		}
	}

	dfs(root, 1);

	cout << "YES\n";
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";


}