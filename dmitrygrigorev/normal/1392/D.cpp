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

	string s;
	cin >> s;

	int ans = 0;
	int start = -1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[0]) {
			start = i;
			break;
		}
	}

	if (start == -1) {
		cout << (n+2)/3 << '\n';
		return;
	}

	int take = 0;
	while (take < n) {
		int cur = (start + take) % n;
		int finish = cur;

		int tot = 0;

		while (s[finish] == s[cur]) {
			take++;
			finish = (finish + 1) % n;
			tot++;
		}

		ans += tot/3;
	}

	cout << ans << '\n';
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}