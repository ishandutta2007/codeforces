#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

int T, n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		int m = n / 2, i = n / 2;
		while (i < n && s[i] == s[m]) {
			i++;
		}
		cout << 2 * (i - m) - n % 2 << endl;
	}

	return 0;
}