#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<int> w;

int ans = 0;

pair<int, int> dfs(int vertex) {
	
	auto a = mp(w[vertex], (int) (gr[vertex].size() == 0));
	for (auto to : gr[vertex]) {
		auto p = dfs(to);
		a.x += p.x;
		a.y += p.y;
	}

	ans = max(ans, (a.x + a.y - 1) / a.y);
	return a;

}

main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	gr.assign(n, {});
	w.assign(n, -1);

	for (int i = 0; i < n-1; ++i) {
		int t;
		cin >> t;
		t--;
		gr[t].pb(i + 1);
	}

	for (auto &x : w) cin >> x;

	dfs(0);

	cout << ans;



}