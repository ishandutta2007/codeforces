#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;

vector<bool> used;
int cnt, ed;

void dfs(int vertex) {

	used[vertex] = true;
	cnt++;

	for (auto to : gr[vertex]) {
		ed++;
		if (used[to]) continue;
		dfs(to);
	}

}

void solve() {
	int n, m;
	cin >> n >> m;

	int ans = 0;

	gr.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}

	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		cnt = 0, ed = 0;
		dfs(i);

		if (cnt == 1) continue;

		ed /= 2;
		if (ed == cnt) ans += cnt + 1;
		else ans += cnt - 1;

	}

	cout << ans << '\n';



}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}