#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int A[101010];
int pos[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			pos[a] = i;
		}
		ll ans = 1;
		int l, r; l = r = pos[0];
		for(int i = 1; i < N; i++) {
			if(pos[i] < l) l = pos[i];
			else if(pos[i] > r) r = pos[i];
			else ans = ans * (r - l + 1 - i) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}