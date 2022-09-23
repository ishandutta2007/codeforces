#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

vector<int> S;
char A[505];
int X;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		S.clear();
		S.push_back(0);
		int l = 1;
		scanf("%d", &X);
		scanf("%s", A + 1);
		int N = strlen(A + 1);

		for(int i = 1; i <= N; i++) S.push_back(A[i] - '0');

		ll ans = N;
		while(l <= X) {
			int sz = S.size(); sz--;

			ans += (ans + MOD - l) * (S[l] - 1);
			ans %= MOD;
			for(int i = 0; i < S[l] - 1; i++) {
				if(S.size() > X) break;
				for(int j = 1; j <= sz - l; j++) {
					if(S.size() > X) break;
					S.push_back(S[j + l]);
				}
			}
			l++;
		}

		printf("%lld\n", ans);
	}
	return 0;
}