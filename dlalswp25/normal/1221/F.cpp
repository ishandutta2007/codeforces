#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct NODE {
	ll v, lz;
	int id;
}T[4 * 505050];

struct POINT {
	int x, y, c;

	bool operator< (const POINT& O) const {
		return y < O.y;
	}
}A[505050];

vector<int> v;

int N;

void propa(int idx, int s, int e) {
	T[idx].v += T[idx].lz;
	if(s != e) {
		T[idx << 1].lz += T[idx].lz;
		T[idx << 1 | 1].lz += T[idx].lz;
	}
	T[idx].lz = 0;
}

void upd(int idx, int s, int e, int p, int q, int x) {
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].lz += x;
		propa(idx, s, e);
		if(s == e) T[idx].id = s;
		return;
	}
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, x);
	upd(idx << 1 | 1, m + 1, e, p, q, x);
	if(T[idx << 1].v < T[idx << 1 | 1].v) T[idx].id = T[idx << 1 | 1].id;
	else T[idx].id = T[idx << 1].id;
	T[idx].v = max(T[idx << 1].v, T[idx << 1 | 1].v);
}

pii get(int idx, int s, int e, int p, int q) {
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return {-(1LL << 60), 0};
	if(p <= s && e <= q) return {T[idx].v, T[idx].id};
	int m = s + e >> 1;
	return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].c);
		if(A[i].x < A[i].y) swap(A[i].x, A[i].y);
		v.push_back(A[i].x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= N; i++) A[i].x = lower_bound(v.begin(), v.end(), A[i].x) - v.begin() + 1;

	int n = v.size();

	for(int i = 0; i < n; i++) upd(1, 1, n, i + 1, i + 1, -v[i]);

	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	int x1 = 2000000000, x2 = 2000000000;
	ll ans = 0;
	A[N + 1].y = 2000000000;

	int p = 1, bef = 1;
	while(p <= N) {
		while(p == bef || A[p].y == A[p - 1].y) {
			upd(1, 1, n, A[p].x, n, A[p].c);
			p++;
		}
		int x = lower_bound(v.begin(), v.end(), A[p - 1].y) - v.begin() + 1;
		pii t = get(1, 1, n, x, n);

		if(ans < t.first + A[p - 1].y) {
			ans = t.first + A[p - 1].y;
			x1 = A[p - 1].y;
			x2 = v[t.second - 1];
		}

		bef = p;
	}
	printf("%lld\n", ans);
	printf("%d %d %d %d\n", x1, x1, x2, x2);

	return 0;
}