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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<pair<int, int> > arr;
	for (int i = 0; i < n; ++i) arr.pb(mp(v[i], i));
	sort(all(arr));

	for (int i = 0; i < n; ++i) v[arr[i].second] = i;

	vector<int> pos;

	vector<pair<int, int> > ans;

	for (int i = 0; i < n; ++i) {
		int cur;
		for (int j = 0; j < n; ++j) if (v[j] == i) cur = j;

		int pref = 0;
		while (pref < pos.size() && pos[pref] < cur) pref++;

		for (int j = ((int) pos.size()) - 1; j >= pref; j--) {
			ans.push_back(mp(cur, pos[j]));
		}

		pos.push_back(cur);
		int u = pos.size() - 1;
		while (u > 0 && pos[u] < pos[u-1]) {
			swap(pos[u], pos[u-1]);
			u--;
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.x+1 << " " << p.y+1 << "\n";
	}

}