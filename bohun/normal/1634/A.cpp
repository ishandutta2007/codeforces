#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n, k;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		auto t = s;
		reverse(t.begin(), t.end());
		cout << (k > 0 && s != t ? 2 : 1) << "\n";
	}

	return 0;
}