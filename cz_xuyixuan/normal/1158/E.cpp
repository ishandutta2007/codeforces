#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, bit[MAXN];
int l[MAXN], r[MAXN], f[MAXN];
int main() {
	read(n), bit[m = 0] = 1, l[1] = r[1] = 0;
	while (bit[m] < n) m++, bit[m] = bit[m - 1] << 1;
	for (int i = 2; i <= n; i++)
		l[i] = 1, r[i] = bit[m] - 1;
	for (int p = m; p >= 2; p--)
	for (int q = 0; q <= 1; q++) {
		string s, t;
		cout << '?' << ' ';
		for (int i = 1; i <= n; i++)
			if (l[i] == r[i] && l[i] / bit[p] % 2 == q) cout << bit[p - 1] << ' ';
			else cout << 0 << ' ';
		cout << endl; cin >> s; s = '0' + s;
		cout << '?' << ' ';
		for (int i = 1; i <= n; i++)
			if (l[i] == r[i] && l[i] / bit[p] % 2 == q) cout << bit[p - 1] - 1 << ' ';
			else cout << 0 << ' ';
		cout << endl; cin >> t; t = '0' + t;
		for (int i = 1; i <= n; i++)
			if (l[i] != r[i] && (l[i] - 1) / bit[p] % 2 == q) {
				assert(s[i] >= t[i]);
				if (s[i] == '0') l[i] += bit[p - 1];
				else if (t[i] == '1') r[i] -= bit[p - 1];
				else l[i] = r[i] = (l[i] + r[i]) / 2;
			}
	}
	for (int i = 1; i <= n; i++)
		assert(l[i] == r[i]);
	for (int p = 0, q = 1; p <= 2; p++, q = (q + 1) % 3) {
		for (int t = 0; t <= m; t++) {
			string s;
			cout << '?' << ' ';
			for (int i = 1; i <= n; i++)
				if (l[i] % 3 == p && (i & bit[t]) != 0) cout << 1 << ' ';
				else cout << 0 << ' ';
			cout << endl; cin >> s; s = '0' + s;
			for (int i = 1; i <= n; i++)
				if (l[i] % 3 == q && s[i] == '1') f[i] |= bit[t];
		}
	}
	cout << '!' << endl;
	for (int i = 2; i <= n; i++)
		cout << i << ' ' << f[i] << endl;
	return 0;
}