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
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = k; i < s.size(); ++i) {
		if (s[i] == '?' && s[i-k] != '?') {
			s[i] = s[i-k];
		}
	}

	reverse(all(s));

	for (int i = k; i < s.size(); ++i) {
		if (s[i] == '?' && s[i-k] != '?') {
			s[i] = s[i-k];
		}
	}

	reverse(all(s));

	int a = 0, b = 0;
	for (int i = 0; i < k; ++i) {
		if (s[i] == '0') a++;
		if (s[i] == '1') b++;
	}

	if (2*a > k || 2*b > k) {
		cout << "NO\n";
		return;
	}

	for (int i = k; i < s.size(); ++i) {
		if (s[i - k] == '0') a--;
		if (s[i - k] == '1') b--;

		if (s[i] == '0') a++;
		if (s[i] == '1') b++;
		if (2*a > k || 2*b > k) {
			cout << "NO\n";
			return;
		}
	}

	for (int i = k; i < s.size(); ++i) {
		if (s[i] != '?' && s[i-k] != '?' && s[i] != s[i-k]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

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

	for (int i = 0; i < t; ++i) solve();

}