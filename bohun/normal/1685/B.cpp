#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl
using ll = long long;
using namespace std;


void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int n = s.size();

	if (count(s.begin(), s.end(), 'A') != a + c + d || count(s.begin(), s.end(), 'B') != b + c + d) {
		cout << "NO\n";
		return;
	}

	int AB = 0, BA = 0;
	vector<int> good, med, bad;

	int i = 0;
	while (i < n - 1) {
		if (s[i] == s[i + 1]) {
			i++;
			continue;
		}

		int j = i;
		while (j + 1 < n && s[j + 1] != s[j]) {
			j++;
		}
		int len = j - i + 1;
		assert(len >= 2);

		if (s[i] == 'A') {
			if (len % 2 == 0) {
				AB += len / 2;
				bad.push_back(len / 2);
			}
			else {
				AB += len / 2;
				med.push_back(len / 2);
			}
		}
		else {
			if (len % 2 == 0) {
				AB += len / 2 - 1;
				good.push_back(len / 2 - 1);
			}
			else {
				AB += len / 2;
				med.push_back(len / 2);
			}
		}

		i = j + 1;
	}

	if (AB < c) {
		cout << "NO\n";
		return;
	}

	if (d == 0) {
		cout << "YES\n";
		return;
	}

	int del = AB - c;

	sort(good.begin(), good.end());
	sort(med.begin(), med.end());
	sort(bad.begin(), bad.end());
	reverse(bad.begin(), bad.end());

	for (auto x : good) {
		int y = min(x, del);
		del -= y;
		BA += y + (x == y);
		if (BA >= d) {
			cout << "YES\n";
			return;
		}
	}

	for (auto x : med) {
		int y = min(x, del);
		del -= y;
		BA += y;
		if (BA >= d) {
			cout << "YES\n";
			return;
		}
	}

	for (auto x : bad) {
		int y = min(x, del);
		del -= y;
		BA += y - 1;
		if (BA >= d) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}