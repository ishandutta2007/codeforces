#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
int n, ans, k;
bool key[MAXN], now[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int cur = n - ((n + i - 1) / i) - (i - 1);
		if (cur > ans) {
			ans = cur;
			k = i;
		}
	}
	if (ans == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n / k; i++)
	for (int j = 1; j <= k - 1; j++)
		key[i * k - j] = true;
	for (int i = n / k * k + 1; i <= n - 1; i++)
		key[i] = true;
	while (true) {
		vector <int> cur;
		for (int i = 1; i <= n; i++)
			if (cur.size() < k && key[i] && !now[i]) {
				cur.push_back(i);
				now[i] = true;
			}
		cout << cur.size();
		for (auto x : cur) cout << ' ' << x;
		cout << endl;
		int res = 0; cin >> res;
		for (int i = 1; i <= cur.size(); i++) {
			now[res] = false;
			res = res % n + 1;
		}
		if (cur.size() < k) {
			cout << 0 << endl;
			return 0;
		}
	}
	return 0;
}