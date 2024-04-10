#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;		

int T, n, cnt;
string s, w = "abacaba", p;

bool match(int x) {
	rep(i, 0, 6)
		if (p[x + i] != w[i]) return false;
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> s;
		p = s;
		rep(i, 0, n - 7) {
			rep(j, 0, n - 1) {
				if (s[j] != '?') p[j] = s[j];
				else if (i <= j && j <= i + 6) p[j] = w[j - i];
				else p[j] = 'z';
			}
			cnt = 0;
			rep(j, 0, n - 7)
				cnt += match(j);
			if (cnt == 1) break;
		}
		if (cnt != 1) cout << "No\n";
		else cout << "Yes\n" << p << endl;
	}
		
	return 0;
}