#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;
const int MX = 100000;

int N;
int A[101010];

struct FWT {
	int T[101010];
	vector<int> w;

	void init() {
		for(int i : w) T[i] = 0;
		w.clear();
	}

	void upd(int x, int v) {
		for(int i = x; i <= MX; i += i&-i) {
			w.push_back(i);
			T[i] += v;
		}
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int query(int a, int b) {
		return get(b) - get(a - 1);
	}
}fwt;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ll ans = 0;
		fwt.init();
		fwt.upd(A[N], 1);
		for(int i = N - 1; i >= 1; i--) {
			vector<pii> tmp;
			int r = MX;
			for(int j = 1; ; j++) {
				int l = (A[i] + j - 1) / j;
				int t = fwt.query(l, r);
				ans += (ll)t * (j - 1) * i;
				ans %= MOD;
				tmp.emplace_back(A[i] / j, t);
				r = l - 1;
				if(!r || r < j) break;
			}
			for(int j = r; j >= 1; j--) {
				int tj = (A[i] + j - 1) / j;
				int t = fwt.query(j, j);
				ans += (ll)t * (tj - 1) * i;
				ans %= MOD;
				tmp.emplace_back(A[i] / tj, t);
			}
			fwt.init();
			for(auto& j : tmp) if(j.first) fwt.upd(j.first, j.second);
			fwt.upd(A[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}