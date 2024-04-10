#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
int cnt[10];

int f(int x) {
	int ret = 0;
	while(x) {
		ret++;
		x /= 10;
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		sort(B + 1, B + N + 1);
		multiset<int> S;
		int ans = 0;
		for(int i = 1; i <= N; i++) S.insert(A[i]);
		for(int i = 1; i <= 9; i++) cnt[i] = 0;
		for(int i = N; i >= 1 && B[i] >= 10; i--) {
			auto it = S.lower_bound(B[i]);
			if(it != S.end() && *it == B[i]) {
				S.erase(it);
			}
			else {
				ans++;
				cnt[f(B[i])]++;
			}
		}
		for(int i = 1; i <= N && B[i] < 10; i++) {
			cnt[B[i]]++;
		}
		for(int i : S) {
			if(i < 10) cnt[i]--;
			else { ans++; cnt[f(i)]--; }
		}
		for(int i = 2; i <= 9; i++) ans += abs(cnt[i]);
		printf("%d\n", ans);
	}
	return 0;
}