#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, P;
int A[202020];
bool chk[202020];
vector<pii> V;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		V.clear();
		scanf("%d%d", &N, &P);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			V.emplace_back(A[i], i);
			chk[i] = false;
		}
		sort(V.begin(), V.end());

		ll ans = 0;
		int lft = N - 1;
		for(auto i : V) {
			if(i.first > P) break;
			int x = i.second;
			if(chk[x]) continue;
			int l = x, r = x;
			while(l > 1 && !chk[l] && A[l - 1] % A[x] == 0) l--;
			while(r < N && !chk[r] && A[r + 1] % A[x] == 0) r++;
			ans += (ll)A[x] * (r - l);
			lft -= (r - l);
			for(int j = l; j <= r; j++) chk[j] = true;
		}
		ans += (ll)P * lft;
		printf("%lld\n", ans);
	}
	return 0;
}