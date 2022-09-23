#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1010101010;

int N;
int A[202020];
int B[202020];
multiset<int> SA, SB;

int f(int x, multiset<int>& S) {
	int ret = INF;
	auto it = S.lower_bound(x);
	if(it != S.end()) ret = min(ret, abs(x - *it));
	if(it != S.begin()) ret = min(ret, abs(x - *prev(it)));
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		SA.clear(); SB.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			SA.insert(A[i]);
		}
		for(int i = 1; i <= N; i++) {
			scanf("%d", &B[i]);
			SB.insert(B[i]);
		}
		ll ans = min(abs(A[1] - B[1]) + abs(A[N] - B[N]), abs(A[1] - B[N]) + abs(A[N] - B[1]));
		for(int i = 1; i <= N; i += N - 1) {
			for(int j = 1; j <= N; j += N - 1) {
				ans = min(ans, (ll)abs(A[i] - B[j]) + f(A[N - i + 1], SB) + f(B[N - j + 1], SA));
			}
		}
		ans = min(ans, (ll)f(A[1], SB) + f(A[N], SB) + f(B[1], SA) + f(B[N], SA));
		printf("%lld\n", ans);
	}
	return 0;
}