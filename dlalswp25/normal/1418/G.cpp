#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int A[505050];
vector<int> v[505050];
int pos[505050];
int cnt[505050];

int lst[505050];

struct NODE {
	int mx, add;
	int cnt;
	NODE() : mx(0), add(0), cnt(0) {}
};

struct SEG {
	NODE T[4 * 505050];

	void init(int idx, int s, int e) {
		T[idx].cnt = e - s + 1;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		// if(idx == 1) printf("upd %d %d %d\n", p, q, x);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].mx += x;
			T[idx].add += x;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		int lft = T[idx << 1].mx, rgt = T[idx << 1 | 1].mx;
		if(lft < rgt) { T[idx].mx = rgt + T[idx].add; T[idx].cnt = T[idx << 1 | 1].cnt; }
		else if(lft > rgt) { T[idx].mx = lft + T[idx].add; T[idx].cnt = T[idx << 1].cnt; }
		else { T[idx].mx = lft + T[idx].add; T[idx].cnt = T[idx << 1].cnt + T[idx << 1 | 1].cnt; }
	}

	pii get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return {0, 0};
		if(p <= s && e <= q) return {T[idx].mx, T[idx].cnt};
		int m = s + e >> 1;
		pii lft = get(idx << 1, s, m, p, q);
		pii rgt = get(idx << 1 | 1, m + 1, e, p, q);
		if(lft.first < rgt.first) return {rgt.first + T[idx].add, rgt.second};
		else if(lft.first > rgt.first) return {lft.first + T[idx].add, lft.second};
		else return {lft.first + T[idx].add, lft.second + rgt.second};
	}
}seg;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) v[i].push_back(0);
	seg.init(1, 1, N);
	for(int i = 1; i <= N; i++) seg.upd(1, 1, N, 1, N, 1);

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		int c = A[i];
		seg.upd(1, 1, N, lst[c] + 1, N, -1);
		seg.upd(1, 1, N, i + 1, N, 1);
		cnt[c]++;
		lst[c] = i;
		v[c].push_back(i);
		if(cnt[c] >= 3) {
			if(cnt[c] > 3) {
				seg.upd(1, 1, N, v[c][pos[c]] + 1, v[c][pos[c] + 1], -1);
				pos[c]++;
			}
			seg.upd(1, 1, N, v[c][pos[c]] + 1, v[c][pos[c] + 1], 1);
		}
		pii t = seg.get(1, 1, N, 1, i);
		// printf("%d %d\n", t.first, t.second);
		if(t.first == N) ans += t.second;
		// printf("%d %lld\n", i, ans);
	}
	printf("%lld\n", ans);

	return 0;
}