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

struct Rectangle {
	int a;
	int b;
	int c; 
	int d;
};

vector<bool> have;

Rectangle find_rectangle() {

	int n = gr.size();

	int BOUND = ceil(sqrt(n));
	have.assign(n, false);

	for (int i = 0; i < n; ++i) {
		int deg = gr[i].size();

		if (deg > BOUND) {
			for (auto x : gr[i]) have[x] = true;

			for (int j = 0; j < n; ++j) {
				if (j == i) continue;
				int a = -1;
				for (auto to : gr[j]) {
					if (have[to]) {
						if (a == -1) a = to;
						else return {i, j, a, to};
					}
				}
			}

			for (auto x : gr[i]) have[x] = false;

		}

		else {
			for (auto x : gr[i]) have[x] = true;

			for (auto to1 : gr[i]) {
				if (gr[to1].size() <= BOUND) {
					for (auto to2 : gr[to1]) {
						if (gr[to2].size() <= BOUND && to2 != i) {
							for (auto to3 : gr[to2]) {
								if (to3 != to1 && have[to3]) {
									return {i, to1, to2, to3};
								}
							}
						}
					}
				}
			}

			for (auto x : gr[i]) have[x] = false;
		}

	}

	return {-1, -1, -1, -1};

}

void solve() {

	int n;
	cin >> n;

	map<int, int> mm;

	vector<vector<int> > arr(n);
	for (auto &x : arr) {
		int k;
		cin >> k;
		x.assign(k, -1);

		for (auto &y : x) {
			cin >> y;
			if (!mm.count(y)) {
				int T = mm.size();
				mm[y] = T;
			}
		}
	}

	for (auto &x : arr) {
		for (auto &y : x) {
			y = mm[y];
		}
	}

	int m = mm.size();
	gr.assign(n + m, {});

	for (int i = 0; i < n; ++i) {
		for (auto x : arr[i]) {
			gr[i].pb(x + n);
			gr[x+n].pb(i);
		}
	}

	auto ans = find_rectangle();

	if (ans.a == -1) {
		cout << "-1\n";
		return;
	}

	if (ans.a < n) {
		cout << ans.a + 1 << " ";
	}

	if (ans.b < n) {
		cout << ans.b + 1 << " ";
	}

	if (ans.c < n) {
		cout << ans.c + 1 << " ";
	}

	if (ans.d < n) {
		cout << ans.d + 1 << " ";
	}

	cout << '\n';



}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}