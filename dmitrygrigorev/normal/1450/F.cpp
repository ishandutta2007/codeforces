#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

	int n;
	cin >> n;

	vector<int> v(n);
	
	for (auto &x : v) {
		cin >> x;
		x--;
	}

	vector<pair<int, int> > seg;
	int start = 0;

	while (start < n) {

		int finish = start + 1;
		while (finish < n && v[finish] != v[finish - 1]) finish++;

		seg.pb(mp(start, finish - 1));
		start = finish;
	}

	vector<int> cnt(n, 0);
	for (auto x : seg) {
		cnt[v[x.x]]++;
		cnt[v[x.y]]++;
	}

	int mx = 0, wh = -1;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			wh = i;
		}
	}

	//cout << mx << " " << wh << endl;

	int need = max(0, mx - 1 - (int) seg.size());

	int can = 0;
	for (auto t : seg) {
		for (int i = t.x ; i < t.y; ++i) {
			if (v[i] != wh && v[i+1] != wh) can++;
		}
	}

	if (can < need) {
		cout << "-1\n";
	}
	else cout << seg.size() - 1 + need << '\n';


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

	for (int i = 0; i < t; ++i) {
		solve();

	}

}