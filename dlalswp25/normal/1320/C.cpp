#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);
const int MX = 1000000;

struct NODE {
	ll mx, add;

	NODE() : mx(-INF), add(0) {}
};

NODE T[4 * 1010101];

struct MOB {
	int x, y, z;
	bool operator< (const MOB& o) const {
		return y < o.y;
	}
};

int N, M, P;
ll AC[1010101];
pair<int, int> B[202020];
MOB C[202020];

void upd(int idx, int s, int e, int p, int q, ll x) {
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) { T[idx].mx += x; T[idx].add += x; return; }
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
	scanf("%d%d%d", &N, &M, &P);
	for(int i = 1; i <= MX; i++) AC[i] = INF;
	for(int i = 1; i <= N; i++) {
		int a, c; scanf("%d%d", &a, &c);
		AC[a] = min(AC[a], (ll)c);
	}
	for(int i = 1; i <= MX; i++) upd(1, 1, MX, i, i, INF - AC[i]);

	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &B[i].first, &B[i].second);
	}
	sort(B + 1, B + M + 1);

	for(int i = 1; i <= P; i++) {
		scanf("%d%d%d", &C[i].x, &C[i].y, &C[i].z);
	}
	sort(C + 1, C + P + 1);

	ll ans = -INF;
	int p = 1;

	for(int i = 1; i <= M; i++) {
		while(p <= P && C[p].y < B[i].first) {
			upd(1, 1, MX, C[p].x + 1, MX, C[p].z);
			p++;
		}
		ans = max(ans, get(1, 1, MX, 1, MX) - B[i].second);
	}
	printf("%lld\n", ans);

	return 0;
}