#include <bits/stdc++.h>
using namespace std;
unsigned long long a[200010];
int cnt[64];
int main() {
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 1, t; i <= n; ++i) {
		scanf("%d", &t);
		a[i] = t;
	}
	unsigned long long ans = 0;
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= n; ++i) {
		unsigned long long t = a[i];
		int j = 0;
		while(t) {
			if(t&1) cnt[j]++;
			j++;
			t >>= 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		unsigned long long t = a[i], r = 0, w = 1;
		for(int i = 0; i < 64; ++i) {
			if(cnt[i] - (t & 1)) r += w;
			t >>= 1;
			w <<= 1;
		}
		t = a[i];
		for(int j = 0; j < k; ++j)
			t *= x;
		r |= t;
		ans = max(ans, r);
	}
	cout << ans << endl;
	return 0;
}