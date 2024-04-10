#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int> > ans;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	while (true) {

		vector<pair<int, int> > blocks;
		int start = 0;

		while (start < n) {
			int finish = start + 1;
			while (finish < n && v[finish - 1] + 1 == v[finish]) finish++;
			blocks.pb(mp(start, finish - 1));

			start = finish;

		}

		if (blocks.size() == 1) break;

		int a, b;
		for (int i = 0; i < blocks.size(); ++i) {
			for (int j = i+1; j < blocks.size(); ++j) {
				int len2 = blocks[j].y - blocks[j].x + 1;
				if (v[blocks[j].x] + len2 == v[blocks[i].x]) {
					a = i;
					b = j;
				}
			}
		}

		vector<int> cur;

		if (a > 0) {
			int T = 0;
			for (int e = 0; e < a; ++e) {
				T += blocks[e].y - blocks[e].x + 1;
			}
			cur.pb(T);
		}

		int T = 0;
		for (int e = a; e < b; ++e) {
			T += blocks[e].y - blocks[e].x + 1;
		}
		cur.pb(T);

		T = 0;
		for (int e = b; e < b + 1; ++e) {
			T += blocks[e].y - blocks[e].x + 1;
		}
		cur.pb(T);

		if (b + 1 < blocks.size()) {
			T = 0;
			for (int e = b + 1; e < blocks.size(); ++e) {
				T += blocks[e].y - blocks[e].x + 1;
			}
			cur.pb(T);
		}

		ans.pb(cur);
		vector<vector<int> > W;
		int u = 0;

		for (auto val : cur) {
			vector<int> here;
			for (int j = 0; j < val; ++j) {
				here.pb(v[u++]);
			}

			W.pb(here);
		}

		reverse(all(W));

		v.clear();
		for (auto x : W) {
			for (auto y : x) v.pb(y);
		}

	} 

	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.size() << " ";
		for (auto y : x) cout << y << " ";
		cout << endl;
	}

}