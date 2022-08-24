#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> solve(string &s) {

	int cnt = 0;
	for (auto x : s) if (x == '0') cnt++;

	vector<int> ans;

	if (2*cnt < s.size()) {
		ans.pb(s.size() - 1);
		reverse(all(s));

		for (auto &x : s) {
			if (x=='0') x = '1';
			else x = '0';
		}

	}

	//cout << s << endl;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') continue;

		if (i > 0) ans.pb(i - 1);
		ans.pb(i);
	}

	//exit(0);

	return ans;
	

}

void solve() {

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	vector<int> a = solve(s), b = solve(t);
	reverse(all(b));

	for (auto x : b) a.pb(x);
	cout << a.size() << "\n";
	for (auto x : a) {
		cout << x+1 << " ";
	}
	cout << "\n";

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