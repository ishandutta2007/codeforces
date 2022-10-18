#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E6+8;
constant big = 999999;

_ n, a[18], m, dp[maxn], x;
deque<_p> q;

int main() {

	memset(dp, -4, sizeof dp);
	dp[0] = 0;

	scanf("%lld", &n);
	for(_ i = 1; i <= 6; ++i) scanf("%lld", &a[i]);
	for(_ i = 1, j = 1; j <= 6; ++j, i *= 10) {
		_ ad = i*3, cn = 3*(n-1);
//		printf("cn = %lld\n", cn);
		if(ad > big) break;
		for(_ k = 0; k < ad; ++k) {
			q.clear();
			for(_ l = k; l <= big; l += ad) {
				for(; !q.empty() && q.back().second+(l-q.front().first)/ad*a[j] <= dp[l]; ) q.pop_back();
				q.push_back(mp(l, dp[l]));
				dp[l] = max(dp[l], q.front().second+(l-q.front().first)/ad*a[j]);
//				if(l == 30 && j == 2) {
//					printf("a[j] = %lld\n", a[j]);
//					printf("dp[l] = %lld\n", dp[l]);
//					printf("(l-q.front().first) = %lld\n", (l-q.front().first));
//					printf("q.size() = %lld, q.front().first = %lld\n", (_)q.size(), q.front().first);
//				}
				for(; !q.empty() && q.front().first <= l-cn*ad; ) q.pop_front();
//				printf("dp[%lld] = %lld\n", l, dp[l]);
			}
		}
	}
	for(_ i = 1, j = 1; j <= 6; ++j, i *= 10) for(_ k = big; k >= 1; --k) {
		for(_ l = 1; l <= 9 && k-i*l >= 0; ++l) {
			_ vl = l%3 ? 0 : l/3*a[j];
			dp[k] = max(dp[k], dp[k-i*l]+vl);
		}
	}
	scanf("%lld", &m);
	for(; m--; ) {
		scanf("%lld", &x);
		printf("%lld\n", dp[x]);
	}

	return 0;
}