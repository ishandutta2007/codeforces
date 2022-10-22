#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int t;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> s;
		map<char, int> m;
		for (auto x : s) m[x]++;
		for (char i = 'a'; i <= 'z'; i++) if (m[i] == 2) cout << i;
		for (char i = 'a'; i <= 'z'; i++) if (m[i] == 2) cout << i;
		for (char i = 'a'; i <= 'z'; i++) if (m[i] == 1) cout << i;
		cout << endl;
	}

	return 0;
}