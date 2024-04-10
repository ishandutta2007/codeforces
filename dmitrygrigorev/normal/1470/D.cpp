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

void solve() {

	int n, m;
	cin >> n >> m;

	gr.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	vector<int> ans(n, 0);

	vector<bool> nt(n, false), ns(n, false);
	vector<bool> used(n, false);

	used[0] = true;

	int res = 0;

	queue<int> q;
	q.push(0);

	vector<int> t;

	while (q.size()) {
		int W = q.front();
		q.pop();

		if (nt[W]) {
			ans[W] = 0;
		}
		else {
			ans[W] = 1;
			t.pb(W);
		}
		res++;

		//cout << W << " " << ans[W] << endl;

		for (auto to : gr[W]) {
			if (used[to]) {
				if (ans[W] == 0) ns[to] = true;
				else nt[to] = true;
				continue;
			}

			used[to] = true;

			if (ans[W] == 0) ns[to] = true;
			else nt[to] = true;
			q.push(to);
		}

	}

	if (res != n) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	sort(all(t));

	cout << t.size() << '\n';
	for (auto x : t) cout << x+1 << " ";
	cout << '\n';



}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}