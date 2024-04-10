#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int T, n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		cout << (n == 1 || (n == 2 && s[0] != s[1]) ? "YES\n" : "NO\n");
	}

	return 0;
}