#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int fa[N], len[N], d[N];

long long get(int n, int k) {
	long long ret = n;
	for (int i = 1; i < n; i++) {
		fa[i] = (i - 1) / k;
		len[i] = len[fa[i]] + 1;
		ret += len[i];
	}
	return ret;
}

long long sums(int l, int r) {
	return (r - l + 1) * 1LL * (l + r) / 2;
}

long long get_lo(int md, int i, int n) {
	return 1LL * i * md + sums(i + 1, i + n - md);
}

void solve(int n, int k, long long s) {
	if (k == 1) {
		for (int i = 2; i <= n; i++) cout << i - 1 << ' ';
		cout << endl;
		return;
	}
	int _n =  n;
	long long _s = s;
	d[0] = 1;
	s -= n;
	n--;
	int cur = 0;
	int i, L = 0;
	for (i = 1; ; i++) {
		int lo = 1, hi = min(1LL * n, d[i - 1] * 1LL * k), md;
		while (lo < hi) {
			md = lo + hi + 1 >> 1;
			if (get_lo(md, i, n) >= s) lo = md;
			else hi = md - 1;
		}
		d[i] = lo;
		n -= d[i];
		s -= 1LL * d[i] * i;
		int cn = 0;
		for (int j = 1; j <= d[i]; j++) {
			cur++;
			fa[cur] = L;
			cn++;
			if (cn == k) cn = 0, L++;
		}
		L = cur - d[i] + 1;
		if (!s) break;
	}
	for (int i = 1; i < _n; i++) {
		cout << fa[i] + 1 << ' ';
		len[i] = len[fa[i]] + 1;
		_s -= len[i];
	}
	assert(_s == _n);
	cout << endl;
}
int main() {
	int n; long long s; cin >> n >> s;
	if (s < 2 * n - 1 || s > 1LL * n * (n + 1) / 2) return cout << "No\n", 0;
	int lo = 1, hi = n - 1, md;
	while (lo < hi) {
	    md = lo + hi >> 1;
	    if (get(n, md) <= s) hi = md;
	    else lo = md + 1;
	}
	cout << "Yes\n";
	solve(n, lo, s);
}