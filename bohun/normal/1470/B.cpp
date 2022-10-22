#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, d[N];

void solve() {
	map<int, int> M;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		map<int, int> cnt;
		int x;
		scanf("%d", &x);
		while (x > 1) {
			cnt[d[x]]++;
			x /= d[x];
		}
		int y = 1;
		for (auto [a, b] : cnt)
			if (b % 2 == 1)
				y *= a;
		M[y]++;
	}
	int ans0 = 0, ans1 = 0, s = M[1];
	for (auto [a, b] : M) {
		ans0 = max(ans0, b);
		ans1 = max(ans1, b);
		if (a != 1 && b % 2 == 0)
			s += b;
	}
	ans1 = max(ans1, s);
	int q;
	scanf("%d", &q);
	while (q--) {
		ll w;
		scanf("%lld", &w);
		printf("%d\n", w == 0 ? ans0 : ans1);
	}
}

int main() {
	for (int i = 2; i < N; ++i)
		if (!d[i]) {
			for (int j = 1; j <= (N - 1) / i; ++j)
				d[i * j] = i;
		}
		
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	
	return 0;
}