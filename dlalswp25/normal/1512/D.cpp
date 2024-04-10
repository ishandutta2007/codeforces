#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		N += 2;
		for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
		sort(B + 1, B + N + 1);
		ll S = 0;
		for(int i = 1; i < N; i++) S += B[i];
		bool ok = false;
		for(int i = 1; i < N; i++) {
			if(S - B[i] == B[N]) {
				swap(B[i], B[N]);
				swap(B[i], B[N - 1]);
				for(int j = 1; j <= N - 2; j++) printf("%lld ", B[j]); puts("");
				ok = true;
				break;
			}
		}
		if(ok) continue;
		if(S - B[N - 1] != B[N - 1]) puts("-1");
		else {
			for(int i = 1; i <= N - 2; i++) printf("%lld ", B[i]); puts("");
		}
	}
	return 0;
}