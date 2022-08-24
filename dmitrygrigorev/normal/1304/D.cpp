#include <bits/stdc++.h>
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

	string s;
	cin >> s;

	vector<int> ans(n);
	
	set<int> unused;
	for (int i = 1; i <= n; ++i) unused.insert(i);
	int cur = 0;
	while (cur < n-1) {
		if (s[cur] == '>') {
			auto it = unused.end();
			it--;
			ans[cur] = (*it);
			unused.erase(it);
			cur++;
			continue;
		}
		else {
			int tot = 0;
			while (cur < n-1 && s[cur] == '<') {
				cur++;
				tot++;
			}
			cur++;
			tot++;
			int was = cur-1;

			for (int i = 0; i < tot; ++i) {
				auto it = unused.end();
				it--;
				ans[was--] = (*it);
				unused.erase(it);
			}
		}
	}
	if (cur == n-1) {
		auto it = unused.end();
		it--;
		ans.back() = (*it);
		unused.erase(it);
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
	cout << "\n";

	for (int i = 1; i <= n; ++i) unused.insert(i);
	cur=0;
	
	while (cur < n-1) {
		if (s[cur] == '<') {
			auto it = unused.begin();
			ans[cur] = (*it);
			unused.erase(it);
			cur++;
			continue;
		}
		else {
			int tot = 0;
			while (cur < n-1 && s[cur] == '>') {
				cur++;
				tot++;
			}
cur++;
			tot++;
			int was = cur-1;

			for (int i = 0; i < tot; ++i) {
				auto it = unused.begin();
				//cout << i << " " << was << endl;
				ans[was--] = (*it);
				unused.erase(it);
			}
		}
	}
	if (cur == n-1) {
		auto it = unused.end();
		it--;
		ans.back() = (*it);
		unused.erase(it);
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
	cout << "\n";


}

main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

	
}