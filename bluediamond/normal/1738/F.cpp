#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif



int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<int> deg(n), guys(n);
		for (int i = 0; i < n; i++) {
			cin >> deg[i];
			guys[i] = i;
		}
		function<int(int)> ask = [&] (int v) {
			v++;
			cout << "? " << v << endl;
			int ret;
			cin >> ret;
			ret--;
			return ret;
		};
		sort(guys.begin(), guys.end(), [&] (int i, int j) {
			return deg[i] > deg[j];
		});
		vector<bool> vis(n, 0);
		int colid = 0;
		vector<int> col(n, -1);
		for (auto &v : guys) {
			if (vis[v]) {
				continue;
			}
			vis[v] = 1;
			vector<int> cur = {v};
			for (int j = 1; j <= deg[v]; j++) {
				int u = ask(v);
				if (vis[u]) {
					for (auto &x : cur) {
						col[x] = col[u];
					}
					break;
				} else {
					vis[u] = 1;
					cur.push_back(u);
				}
			}
			if (col[v] == -1) {
				for (auto &j : cur) {
					col[j] = colid;
					
				}
				colid++;
			}
		}
		cout << "! ";
		for (auto &c : col) {
			assert(c != -1);
			cout << c + 1 << " ";
		}
		cout << endl;
	}

	
	return 0;
}