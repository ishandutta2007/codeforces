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
	vector<bool> have(n, false);
	vector<int> cnt(n, 0);

	int tot = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
		if (!have[v[i]]) {
			have[v[i]] = true;
			tot++;
		}
		cnt[v[i]]++;
	}

	if (tot == n) cout << '1';
	else cout << '0';

	int cur = 0, l = 0, r = n-1;
	while (l < r) {
		if (v[l] == cur && cnt[cur] == 1) {
			cur++, l++;
		}
		else if (v[r] == cur && cnt[cur] == 1) {
			cur++, r--;
		}
		else break;
	}

	cur++;

	for (int i = 0; i < n; ++i) {
		if (!cnt[i]) cur = min(cur, i);
	}

	cur = min(cur, n - 1);

	for (int j = 0; j < n-1-cur; ++j) cout << '0';
	for (int j = 0; j < cur; ++j) cout << '1';

	cout << '\n';


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