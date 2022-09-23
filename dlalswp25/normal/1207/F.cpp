#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int SZ = 700;

ll ans[707][707];
int Q;
ll A[505050];

int main() {
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int x, y; scanf("%d%d", &x, &y);
			A[x] += y;
			for(int j = 1; j <= SZ; j++) {
				ans[j][x % j] += y;
			}
		}
		else {
			int x, y; scanf("%d%d", &x, &y);
			if(x > SZ) {
				ll ret = 0;
				for(int j = y; j <= 500000; j += x) {
					ret += A[j];
				}
				printf("%lld\n", ret);
			}
			else {
				printf("%lld\n", ans[x][y]);
			}
		}
	}

	return 0;
}