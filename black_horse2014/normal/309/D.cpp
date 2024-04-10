#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int N = 32002;

int sqr[N];

int main() {
	for (int i = 0; i < N; i++) {
		sqr[i] = i * i;
	}
	int n, m; cin >> n >> m;
	++n, ++m;
	int hn = (n) / 2;
	long long cnt = 0, mcnt = 0;
	for (int i = m; i <= hn; i++) {
		int st = 0, en = n - m;
		while (st < en) {
			int md = (st + en + 1) / 2;
			if (sqr[i] - i * md + sqr[md] + sqr[n-i] - (n-i) * m + sqr[m] >= sqr[n-md] + sqr[n-m] - (n-md) * (n-m)) en = md - 1;
			else st = md;
		}
		if (i + i == n) {
			int j = st, k = m;
			for (; j >= m && k <= n - m; j--, mcnt += (min(n-m+1, k) - m)) {
				while (sqr[i] + sqr[j] - i*j + sqr[n-i] + sqr[k] - (n-i)*k < sqr[n-j] + sqr[n-k] - (n-j)*(n-k)) ++k;
			}
			mcnt += (n - m - m + 1) * (j - m + 1);
		} else {
			int j = st, k = m;
			for (; j >= m && k <= n - m; j--, cnt += (min(n-m+1, k) - m)) {
				while (sqr[i] + sqr[j] - i*j + sqr[n-i] + sqr[k] - (n-i)*k < sqr[n-j] + sqr[n-k] - (n-j)*(n-k)) ++k;
			}
			cnt += (n - m - m + 1) * (j - m + 1);
		}
	}
	cout << (cnt + cnt + mcnt) * 3 << endl;
}