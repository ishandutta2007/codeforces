#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, Q;
int A[202020];
ll ans = 0;

int S[202020];
map<pii, int> mp;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		ans += A[i];
	}

	int waste = 0;
	int cnt = 0;

	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		int s, t, u; scanf("%d%d%d", &s, &t, &u);
		if(mp[{s, t}]) {
			int tu = mp[{s, t}];
			if(S[tu] >= A[tu] + 1) waste--;
			S[tu]--;
			cnt--;
		}

		if(u && S[u] >= A[u]) waste++;
		mp[{s, t}] = u;
		S[u]++;
		if(u) cnt++;

		printf("%lld\n", ans - cnt + waste);
	}

	return 0;
}