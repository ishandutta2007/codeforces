#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1010101010;

int N;
int A[505050];
ll S[505050];
int D[505050];

struct SegTree {
	int base;
	int T[1050505];

	void init(int n) {
		base = 1;
		while(base < n) base <<= 1;
		for(int i = 2 * base - 1; i >= 0; i--) T[i] = -INF;
	}

	void upd(int p, int v) {
		p += base; p--;
		T[p] = max(T[p], v);
		while(p > 1) {
			p >>= 1;
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}

	int query(int p, int q) {
		if(q < p) return -INF;
		p += base; q += base;
		p--; q--;
		int ret = -INF;
		while(p <= q) {
			if(p & 1) ret = max(ret, T[p++]);
			if(~q & 1) ret = max(ret, T[q--]);
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		S[0] = 0;
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
		seg.init(N + 1);
		vector<ll> v;
		for(int i = 0; i <= N; i++) v.push_back(S[i]);

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 0; i <= N; i++) S[i] = lower_bound(v.begin(), v.end(), S[i]) - v.begin() + 1;
		seg.upd(S[0], 0);
		map<ll, int> mp;
		mp[S[0]] = 0;
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			D[i] = seg.query(1, S[i] - 1) + i;
			if(mp.find(S[i]) != mp.end()) D[i] = max(D[i], mp[S[i]]);
			D[i] = max(D[i], mx - i);

			seg.upd(S[i], D[i] - i);
			if(mp.find(S[i]) == mp.end()) mp[S[i]] = D[i];
			else mp[S[i]] = max(mp[S[i]], D[i]);
			mx = max(mx, D[i] + i);
		}
		printf("%d\n", D[N]);
	}
	return 0;
}