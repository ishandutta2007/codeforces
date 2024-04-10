#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
ll S[101010];
vector<int> v;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		v.clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			v.push_back(A[i]);
		}
		for(int i = 1; i <= N; i++) S[i] = 0;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1; i <= N; i++) A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += (N - i + 1) * S[A[i]];
			S[A[i]] += i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}