#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char A[101010];
char B[101010];
vector<int> V[30];

struct BIT {
	int T[101010];

	void init() {
		for(int i = 1; i <= N; i++) T[i] = 0;
	}

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < 26; i++) V[i].clear();
		fwt.init();
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);

		for(int i = 1; i <= N; i++) V[A[i] - 'a'].push_back(i);
		for(int i = 0; i < 26; i++) reverse(V[i].begin(), V[i].end());

		ll ans = (ll)N * N;

		ll cur = 0;
		for(int i = 1; i <= N; i++) {
			int c = B[i] - 'a';
			for(int j = 0; j < c; j++) {
				if(!V[j].size()) continue;
				int t = V[j].back();
				t += fwt.get(N) - fwt.get(t);
				ans = min(ans, cur + (t - i));
			}
			if(!V[c].size()) break;
			int t = V[c].back();
			fwt.upd(t, 1);
			t += fwt.get(N) - fwt.get(t);
			cur += (t - i);
			V[c].pop_back();
		}

		if(ans >= (ll)N * N) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}