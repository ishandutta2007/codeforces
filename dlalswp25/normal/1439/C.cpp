#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[202020];
int S[4 * 202020];
int E[4 * 202020];

struct NODE {
	ll mx;
	ll sum, lz;
}T[4 * 202020];

vector<int> v;

void init(int idx, int s, int e) {
	S[idx] = s; E[idx] = e;
	if(s == e) return;
	int m = s + e >> 1;
	init(idx << 1, s, m);
	init(idx << 1 | 1, m + 1, e);
}

void propa(int idx, int s, int e) {
	if(T[idx].lz) {
		T[idx].mx = T[idx].lz;
		T[idx].sum = T[idx].mx * (e - s + 1);
	}
	if(s != e) {
		T[idx << 1].lz = max(T[idx << 1].lz, T[idx].lz);
		T[idx << 1 | 1].lz = max(T[idx << 1 | 1].lz, T[idx].lz);
	}
	T[idx].lz = 0;
}

ll fd(int idx, int s, int e, int x) {
	propa(idx, s, e);
	if(s == e) {
		if(T[idx].mx <= x) return s;
		else return s + 1;
	}

	int m = s + e >> 1;
	propa(idx << 1, s, m);
	propa(idx << 1 | 1, m + 1, e);
	if(T[idx << 1 | 1].mx > x) return fd(idx << 1 | 1, m + 1, e, x);
	return fd(idx << 1, s, m, x);
}

void upd(int idx, int s, int e, int p, int q, int x) {
	propa(idx, s, e);
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].lz = x;
		propa(idx, s, e);
		return;
	}

	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, x);
	upd(idx << 1 | 1, m + 1, e, p, q, x);
	T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	T[idx].sum = T[idx << 1].sum + T[idx << 1 | 1].sum;
}

void get_intervals(int idx, int s, int e, int p, int q) {
	propa(idx, s, e);
	if(q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		v.push_back(idx);
		return;
	}
	int m = s + e >> 1;
	get_intervals(idx << 1, s, m, p, q);
	get_intervals(idx << 1 | 1, m + 1, e, p, q);
}

ll fd2(int idx, int s, int e, int& y) {
	propa(idx, s, e);
	if(s == e) {
		if(T[idx].sum <= y) return s + 1;
		else return s;
	}

	int m = s + e >> 1;
	propa(idx << 1, s, m);
	propa(idx << 1 | 1, m + 1, e);
	if(T[idx << 1].sum > y) return fd2(idx << 1, s, m, y);
	y -= T[idx << 1].sum;
	return fd2(idx << 1 | 1, m + 1, e, y);
}

int main() {
	scanf("%d%d", &N, &Q);
	init(1, 1, N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		upd(1, 1, N, i, i, A[i]);
	}

	while(Q--) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if(t == 1) {
			int a = fd(1, 1, N, y);
			if(a <= x) upd(1, 1, N, a, x, y);
		}
		else {
			int pos = x;
			int ans = 0;
			while(1) {
				if(pos > N) break;
				int a = fd(1, 1, N, y);
				a = max(a, pos);
				if(a > N) break;

				v.clear();
				get_intervals(1, 1, N, a, N);
				for(int i : v) {
					// printf("%d %d %d\n", i, S[i], E[i]);
					propa(i, S[i], E[i]);
					if(T[i].sum > y) {
						int r = fd2(i, S[i], E[i], y);
						ans += r - S[i];
						pos = r;
						break;
					}
					else {
						ans += E[i] - S[i] + 1;
						// printf("%lld\n", T[i].sum);
						y -= T[i].sum;
						pos = E[i] + 1;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}