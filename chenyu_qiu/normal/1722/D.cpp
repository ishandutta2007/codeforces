#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long tot = 0;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			v.push_back((n - 1 - i) - i);
			tot += i;
		}
		else {
			v.push_back(i - (n - 1 - i));
			tot += n - 1 - i;
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {tot += v[i];}
		cout << tot << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}