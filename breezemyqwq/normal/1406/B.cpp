#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const ll inf = -9223372036854775807;

int t1[N], t2[N], cnt1, cnt2;
long long ans;

int main() {
	int T;
	cin >> T;
	while(T--) {
		cnt1 = cnt2 = 0;
		memset(t1, 0, sizeof t1);
		memset(t2, 0, sizeof t2);
		int n;
		scanf("%d", &n);
		ans = inf;
		for(int i = 1; i <= n; i++) {
			int k;
			scanf("%d", &k);
			if(k < 0) t1[++cnt1] = k;
			else t2[++cnt2] = k;
		}
		sort(t1 + 1, t1 + cnt1 + 1, greater<int>());
		sort(t2 + 1, t2 + cnt2 + 1, greater<int>());
		for(int i = 0; i <= 5; i++) {
			if(i > cnt1 || (5 - i) > cnt2) continue;
			long long now = 1;
			if(i & 1) {
				for(int j = 1; j <= i; j++) now *= t1[j];
				for(int j = cnt2; j >= cnt2 - (5 - i) + 1; j--) now *= t2[j];
			}
			else {
				for(int j = cnt1; j >= cnt1 - i + 1; j--) now *= t1[j];
				for(int j = 1; j <= (5 - i); j++) now *= t2[j];
			}
			ans = max(ans, now);
		}
		printf("%lld\n", ans);
	}
	return 0;
}