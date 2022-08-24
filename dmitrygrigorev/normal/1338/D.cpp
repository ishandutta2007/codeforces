#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int ans=0;
vector<vector<int> >data;

void relax(int &a, int &b, int c) {
	if (c > a) {
		b = a;
		a = c;
	}
	else b = max(b, c);
}

pair<int, int> dfs(int vertex, int last) {

	int take = 0, take2 = 0, non = 0, non2 = 0;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		pair<int, int> res = dfs(to, vertex);

		relax(take, take2, res.second);
		relax(non, non2, max(res.second, res.first));

	}

	ans = max(ans, take2 + take + 1);
	ans = max(ans, non2 + non + max(0, (int) data[vertex].size() - 2));
	ans = max(ans, non + max(0, (int) data[vertex].size() - 1));

	non += data[vertex].size() - 2;

	return {take + 1, non};

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
		data[u-1].push_back(v-1);
		data[v-1].push_back(u-1);
	}

	dfs(0, -1);

	cout << ans;


}