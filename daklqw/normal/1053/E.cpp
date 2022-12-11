#include <bits/stdc++.h>

const int MAXN = 1000010;
void bye() { std::cout << "no" << std::endl; exit(0); }
int n, A[MAXN], nxt[MAXN], hav[MAXN];
int pre[MAXN], suc[MAXN];
void delseg(int l, int r) {
	suc[pre[l]] = suc[r], pre[suc[r]] = pre[l];
}
int newnode() {
	static int cnt = 1;
	while (hav[cnt]) ++cnt;
	return cnt++;
}
void solve(int l, int r, int fa) {
	if ((r - l) & 1) bye();
	int tot = 0, cur = 0;
	for (int u = l; u <= r; u = suc[u]) {
		if (nxt[u]) {
			int lst = u, now = nxt[u]; 
			while (now) {
				if (now > r) bye();
				solve(suc[lst], pre[now], A[u]);
				lst = now, now = nxt[now];
			}
			delseg(suc[u], lst);
		}
		++tot, cur += A[u] > 0;
	}
	if (cur * 2 > tot + 1) bye();
	for (int u = l; u <= r && cur * 2 < tot; u = suc[u])
		if (!A[u]) ++cur, A[u] = newnode();
	static int lf[MAXN];
	for (int u = l; u <= r; ) {
		int x = u, y = suc[u], z = suc[suc[u]];
		if (z > r) break;
		lf[u] = (pre[u] < l || lf[pre[u]]) && A[u];
		if (A[y] && ((!A[x]) + (!A[z]) == 1)) {
			A[x] = A[z] = A[x] | A[z];
			delseg(y, z);
			while (pre[u] >= l && A[u] && (!lf[suc[u]] || suc[u] > r))
				u = pre[u];
		} else u = suc[u];
	}
	for (int u = l; u <= r; u = suc[u]) if (!A[u]) A[u] = fa;
	// only R x.x.x.x R
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	const int L = n * 2 - 1;
	for (int i = 1; i <= L; ++i) std::cin >> A[i], hav[A[i]] = true;
	if (!A[1] || !A[L]) A[1] = A[L] = A[1] | A[L];
	if (A[1] != A[L]) bye();
	static int lst[MAXN];
	for (int i = 1; i <= L; ++i) {
		if (A[i] && lst[A[i]]) nxt[lst[A[i]]] = i;
		lst[A[i]] = i;
		pre[i] = i - 1, suc[i] = i + 1;
	}
	solve(1, L, -12243);
	memset(lst, 0, sizeof lst);
	std::cout << "yes" << std::endl;
	for (int i = 1; i <= L; ++i) std::cout << A[i] << ' ';
	return 0;
}