#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char S[101010];
map<int, int> mp;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);
		mp.clear();
		mp[0]++;

		int sum = 0;
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			sum += S[i] - '0';
			ans += mp[i - sum];
			mp[i - sum]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}