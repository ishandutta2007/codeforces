#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, D, M;
vector<int> A;
vector<int> B;

ll SA[101010];
ll SB[101010];

int main() {
	scanf("%d%d%d", &N, &D, &M);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		if(x <= M) A.push_back(x);
		else B.push_back(x);
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());

	for(int i = 1; i <= A.size(); i++) {
		SA[i] = SA[i - 1] + A[i - 1];
	}
	for(int i = 1; i <= B.size(); i++) {
		SB[i] = SB[i - 1] + B[i - 1];
	}

	ll ans = (B.size() == 0 ? SA[N] : 0);

	for(int i = 1; i <= N; i++) {
		if(i > B.size()) continue;
		ll mn = (ll)(D + 1) * (i - 1) + 1;
		ll mx = (ll)(D + 1) * i;
		if(mn > N) continue;
		if(N - mx > (int)A.size()) continue;
		if(N - mn > (int)A.size()) {
			ans = max(ans, SB[i] + SA[(int)A.size()]);
		}
		else ans = max(ans, SB[i] + SA[N - mn]);
	}
	printf("%lld\n", ans);
	return 0;
}