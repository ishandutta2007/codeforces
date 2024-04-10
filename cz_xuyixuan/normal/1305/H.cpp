#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
int n, m, q, l[MAXN], r[MAXN], x[MAXN];
int a[MAXN]; ll t, sa[MAXN], sl[MAXN], sr[MAXN];
bool check() {
	for (int i = 1; i <= m; i++)
		sa[i] = sa[i - 1] + a[i];
	for (int i = 0, j = m; i <= n; i++) {
		while (j >= 1 && a[j] >= n - i) j--;
		if (sl[i] + sa[j] + 1ll * (n - i) * (m - j) < sl[n]) return false;
		if (sr[i] + sa[j] + 1ll * (n - i) * (m - j) < t) return false;
	}
	return true;
}
bool check(int cnt, int val) {
	ll sum = 0; bool flg = true;
	for (int i = 1; i <= m; i++) {
		a[i] = max(a[i - 1], x[i]), sum += a[i];
		if (m - i + 1 <= cnt) flg &= x[i] == -1;
	}
	if (!flg) {
		if (a[m] < val) return false;
		for (int i = 1; i <= cnt; i++) {
			if (x[m - i + 1] != -1 && a[m - i + 1] != a[m]) return false;
			sum += a[m] - a[m - i + 1];
			a[m - i + 1] = a[m];
		}
	} else {
		for (int i = 1; i <= cnt; i++) {
			if (a[m - i + 1] < val) {
				sum += val - a[m - i + 1];
				a[m - i + 1] = val;
			}
		}
	}
	if (sum > t) return false;
	sum = t - sum; ll bak = sum;
	for (int i = 1, last = 0; i <= m; i++)
		if (x[i] != -1 || m - i + 1 <= cnt) {
			int rng = i - last - 1, inc = a[i] - a[last];
			if (1ll * inc * rng <= sum) {
				sum -= 1ll * inc * rng;
				for (int j = last + 1; j <= i - 1; j++)
					a[j] += inc;
			} else {
				inc = sum / rng, sum -= 1ll * inc * rng;
				for (int j = last + 1; j <= i - 1; j++) {
					a[j] += inc;
					if (i - j <= sum) a[j]++;
				} sum = 0;
				break;
			}
			last = i;
		}
	if (!flg) {
		if (sum != 0) return false;
	} else {
		if (sum != 0) {
			int tmp = cnt;
			while (tmp < m && x[m - tmp] == -1) tmp++;
			ll inc = (sum - 1) / tmp + 1;
			for (int i = 1; i <= m; i++) {
				a[i] = max(a[i - 1], x[i]);
				if (m - i + 1 <= cnt) chkmax(a[i], val);
			}
			if (a[m] + inc > n) return false;
			for (int i = 1; i <= cnt; i++)
				a[m - i + 1] += inc;
			sum = bak - inc * cnt;
			if (sum < 0) return false;
			for (int i = 1, last = 0; i <= m; i++)
				if (x[i] != -1 || m - i + 1 <= cnt) {
					int rng = i - last - 1, inc = a[i] - a[last];
					if (1ll * inc * rng <= sum) {
						sum -= 1ll * inc * rng;
						for (int j = last + 1; j <= i - 1; j++)
							a[j] += inc;
					} else {
						inc = sum / rng, sum -= 1ll * inc * rng;
						for (int j = last + 1; j <= i - 1; j++) {
							a[j] += inc;
							if (i - j <= sum) a[j]++;
						} sum = 0;
						break;
					}
					last = i;
				}
			if (sum != 0) return false;
		}
	}
	return check();
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(l[i]), read(r[i]);
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; i++) {
		sl[i] = sl[i - 1] + l[i];
		sr[i] = sr[i - 1] + r[i];
	}
	for (int i = 1; i <= m; i++)
		x[i] = -1;
	read(q);
	for (int i = 1; i <= q; i++) {
		int pos; read(pos);
		read(x[m - pos + 1]);
	}
	read(t);
	if (!check(1, 0)) {
		puts("-1 -1");
		return 0;
	}
	int l = 1, r = m;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid, 0)) l = mid;
		else r = mid - 1;
	}
	int cnt = l; l = 0, r = n;
	cout << cnt << ' ';
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(cnt, mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}