#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int ans = 0;
		ll sum = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			sum += a;
			if(sum == (ll)i * (i + 1) / 2) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}