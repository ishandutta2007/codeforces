#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];

int main() {
	int i, j;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		map <long long, long long> s;
		long long sum = 0;
		for(i=1;i<=n;i++){
			scanf("%lld", &a[i]);
			sum += a[i];
		}

		long long ans = 0;
		for(i=1;i<=n;i++){
			ans += s[2 * sum - n * a[i]];
			s[a[i] * n]++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}