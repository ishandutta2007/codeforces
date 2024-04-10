#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>


const int MAXN = 200010;
const int INF = 0x3f3f3f3f;
int A[MAXN], B[MAXN], li[MAXN], bak, n, m;
int f[MAXN], st[MAXN], top, at[MAXN];
int cnt[MAXN], nt[MAXN];
struct cmp { bool operator () (int a, int b) { return A[a] == A[b] ? a < b : A[a] < A[b]; } };
typedef __gnu_pbds::priority_queue<int, cmp, __gnu_pbds::pairing_heap_tag> heap;
heap H[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		if (A[i] != -1) li[++bak] = A[i];
	}
	std::cin >> m;
	for (int i = 1; i <= m; ++i) std::cin >> B[i], li[++bak] = B[i];
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	for (int i = 1; i <= n; ++i) if (A[i] != -1)
		A[i] = std::lower_bound(li + 1, li + 1 + bak, A[i]) - li;
	for (int i = 1; i <= m; ++i)
		B[i] = std::lower_bound(li + 1, li + 1 + bak, B[i]) - li;
	for (int i = 1; i <= m; ++i) ++cnt[B[i]];
	std::sort(B + 1, B + 1 + m);
	for (int i = 1; i <= n; ++i) {
		if (A[i] == -1) {
			int cur = 1;
			if (st[top] < B[m])
				st[++top] = B[m], at[top] = i, f[i] = top;
			for (int j = 1; j <= top; ++j) {
				while (cur <= m && B[cur] <= st[j - 1]) ++cur;
				if (cur <= m && B[cur] <= st[j])
					nt[j] = B[cur], at[j] = i, f[i] = j;
			}
			for (int j = 1; j <= top; ++j)
				if (nt[j]) st[j] = nt[j], nt[j] = 0;
		} else {
			int a = std::lower_bound(st + 1, st + 1 + top, A[i]) - st;
			if (a > top) ++top, st[top] = INF;
			if (A[i] < st[a]) st[a] = A[i], at[a] = i;
			f[i] = a;
		}
	}
	int ans = *std::max_element(f + 1, f + 1 + n);
	int now = n + 1, vnow = bak + 1;
	for (int i = 1; i <= n; ++i) H[f[i]].push(i);
	for (int i = ans; i; --i) {
		H[i].join(H[i + 1]);
		while (true) {
			int t = H[i].top(); H[i].pop();
			if (t < now && f[t] >= i) {
				int can;
				if (A[t] == -1) {
					can = std::lower_bound(B + 1, B + 1 + m, vnow) - B - 1;
					if (can) A[t] = B[can], --cnt[B[can]];
				} else can = A[t] < vnow;
				if (can) { vnow = A[t], now = t; break; }
			}
		}
	}
	int cur = 1;
	for (int i = 1; i <= n; ++i) { 
		if (A[i] == -1) { while (!cnt[cur]) ++cur; --cnt[A[i] = cur]; }
		std::cout << li[A[i]] << (" \n" [i == n]);
	}
	return 0;
}