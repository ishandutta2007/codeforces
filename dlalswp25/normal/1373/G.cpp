#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1010101010;

int N, M, K;

struct NODE {
	ll mx;
	ll add;
}T[4 * 404040];

int cnt[404040];
map<pair<int, int>, int> mp;

void upd(int idx, int s, int e, int p, int q, ll x) {
	// printf("%d %d %lld\n", p, q, x);
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].mx += x;
		T[idx].add += x;
		return;
	}
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, x);
	upd(idx << 1 | 1, m + 1, e, p, q, x);
	T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx) + T[idx].add;
}

ll get(int idx, int s, int e, int p, int q) {
	if(q < p || q < s || e < p) return -INF;
	if(p <= s && e <= q) return T[idx].mx;
	int m = s + e >> 1;
	return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q)) + T[idx].add;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= 2 * N; i++) upd(1, 1, 2 * N, i, i, -INF);
	while(K--) {
		int x, y; scanf("%d%d", &x, &y);

		int t = mp[{x, y}];
		mp[{x, y}] = 1 - t;

		y += abs(M - x);

		if(t == 0) {
			if(cnt[y] == 0) {
				upd(1, 1, 2 * N, y, y, y + INF);
			}
			upd(1, 1, 2 * N, 1, y, 1);
			cnt[y]++;
		}
		else {
			if(cnt[y] == 1) {
				upd(1, 1, 2 * N, y, y, -INF - y);
			}
			upd(1, 1, 2 * N, 1, y, -1);
			cnt[y]--;
		}

		printf("%lld\n", max(0LL, get(1, 1, 2 * N, 1, 2 * N) - N - 1));
	}
	return 0;
}