#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <complex>
#include <functional>
#include <iomanip>
using namespace std;
#define mx 800005
#define MN 200005
#define inf 2000000005
int N, K, D, a[MN], f[MN], g[MN];
map <int, int> M;
struct Seg_Tree {
	int A[mx], I[mx], ma[mx], mi[mx], id[mx], opt[mx];
	void update(int t) {
		int L, R;
		L = t << 1; R = L + 1;
		ma[t] = min(ma[L], ma[R]);
		mi[t] = min(mi[L], mi[R]);
		opt[t] = min(opt[L], opt[R]);
	}
	void renew(int t, int v, int flag) {
		if (flag) ma[t] = v, A[t] = v;
		else mi[t] = id[t] - v, I[t] = v;
		opt[t] = ma[t] + mi[t];
	}
	void _down(int t) {
		if (A[t]) renew(t << 1, A[t], 1), renew(t * 2 + 1, A[t], 1), A[t] = 0;
		if (I[t]) renew(t << 1, I[t], 0), renew(t * 2 + 1, I[t], 0), I[t] = 0;
	}
	void modify(int t, int l, int r, int ll, int rr, int v, int flag) {
		if (l == ll && r == rr) {
			renew(t, v, flag); return;
		}
		int mid = l + r >> 1; _down(t);
		if (rr <= mid) modify(t << 1, l, mid, ll, rr, v, flag);
		else if (ll > mid) modify(2 * t + 1, mid + 1, r, ll, rr, v, flag);
		else modify(t << 1, l, mid, ll, mid, v, flag), modify(2 * t + 1, mid + 1, r, mid + 1, rr, v, flag);
		update(t);
	}
	void build(int t, int l, int r) {
		if (l == r) {
			id[t] = l, ma[t] = opt[t] = inf; return;
		}id[t] = l, ma[t] = opt[t] = inf;
		int mid = l + r >> 1;
		build(t << 1, l, mid); build(2 * t + 1, mid + 1, r);
	}
	int get(int t, int l, int r, int k) {
		if (l == r) {
			if (opt[t] <= k) return l;
			else return inf;
		}int mid = l + r >> 1;
		_down(t);
		if (opt[t << 1] <= k) return get(t << 1, l, mid, k);
		else return get(t * 2 + 1, mid + 1, r, k);
	}
	
}T;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	cin >> N >> K >> D;
	int i, st, en, last(0), rlt(0);
	T.build(1, 1, N);
	for (i = 1; i <= N; i ++) scanf("%d", a + i), a[i] += 1000000001;
	if (!D) {
		for (i = 1; i <= N; i ++) {
			if (i > 1 && a[i] != a[i - 1]) last = i - 1;
			if (i - last > rlt) rlt = i - last, st = last + 1, en = i;
		}
	} else {
		for (i = 1; i <= N; i ++) {
			
			last = max(last, M[a[i]]); M[a[i]] = i;
			if (i > 1 && a[i] % D != a[i - 1] % D) last = i - 1;
			while (f[0] && a[f[f[0]]] < a[i]) -- f[0];
			
			while (g[0] && a[g[g[0]]] > a[i]) -- g[0];
			T.modify(1, 1, N, f[f[0]] + 1, i, a[i] / D, 1);
			f[++ f[0]] = i;
			T.modify(1, 1, N, g[g[0]] + 1, i, a[i] / D, 0);
			g[++ g[0]] = i;
			if (last)
				T.modify(1, 1, N, 1, last, inf, 1);
			int p = T.get(1, 1, N, K + i);
			if (i - p + 1 > rlt) rlt = i - p + 1, st = p, en = i;
		}
	}
	printf("%d %d\n", st, en);
}