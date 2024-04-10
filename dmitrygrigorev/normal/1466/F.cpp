#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int f;
	int r;
};

vector<Vertex> snm;

int get(int v) {
	if (snm[v].f != v) {
		snm[v].f = get(snm[v].f);
	}
	return snm[v].f;
} 

void unite(int u, int v) {
	if (snm[u].r > snm[v].r) swap(u, v);
	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;
}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int last = -1;

	int n, m;
	cin >> n >> m;

	vector<int> ans;

	for (int i = 0; i < m; ++i) {
		snm.pb({i, 1});
	}

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		if (k == 1) {
			int x;
			cin >> x;
			x--;

			if (last == -1) {
				ans.pb(i);
				last = x;
			}

			else {
				int p1 = get(last), p2 = get(x);
				if (p1 == p2) continue;
				unite(p1, p2);
				ans.pb(i);
			}

		}

		else {
			int x, y;
			cin >> x >> y;
			x--, y--;
			int p1 = get(y), p2 = get(x);
			if (p1 == p2) continue;
			unite(p1, p2);
			ans.pb(i);
		}
	} 

	int mod = 1000000007;
	int w = 1;

	for (int i = 0; i < ans.size(); ++i) {
		w = ((ll) w * 2) % mod;
	}

	cout << w << " " << ans.size() << '\n';
	for (auto x : ans) cout << x+1 << " ";


}