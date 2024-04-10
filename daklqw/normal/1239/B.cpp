#include <bits/stdc++.h>

const int MAXN = 300010;
char buf[MAXN];
int n, pre[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1;
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + (buf[i] == '(' ? 1 : -1);
	if (pre[n] != 0) return std::cout << "0\n1 1\n", 0;
	int mi = 0;
	for (int i = 1; i <= n; ++i) mi = std::min(mi, pre[i]);
	int ans = 0, ax = 1, ay = 1;
	for (int i = 1; i <= n; ++i) ans += pre[i] == mi;
	int bse = ans;
	static int suc[MAXN];
	for (int i = n; i; --i) suc[i] = suc[i + 1] + (pre[i] == mi + 2);
	int rcur = 0, lst;
	for (int i = 1; i <= n; ++i) {
		if (rcur < i) rcur = i, lst = -1;
		while (rcur <= n && pre[rcur] >= mi + 2) {
			++rcur;
			if (buf[rcur] == ')') lst = rcur;
		}
		if (buf[i] == '(' && lst != -1) {
			if (bse + suc[i] - suc[lst] > ans)
				ans = bse + suc[i] - suc[lst], ax = i, ay = lst;
		}
	}
	for (int i = n; i; --i) suc[i] = suc[i + 1] + (pre[i] == mi + 1);
	rcur = 0;
	for (int i = 1; i <= n; ++i) {
		if (rcur < i) rcur = i, lst = -1;
		while (rcur <= n && pre[rcur] >= mi + 1) {
			++rcur;
			if (buf[rcur] == ')') lst = rcur;
		}
		if (buf[i] == '(' && lst != -1) {
			if (suc[i] - suc[lst] > ans)
				ans = suc[i] - suc[lst], ax = i, ay = lst;
		}
	}
	int fir = -1;
	for (int i = 1; i <= n; ++i) if (pre[i] == mi)
		fir = fir == -1 ? i : fir, lst = i + 1;
	while (fir && buf[fir] != ')') --fir;
	while (lst <= n && buf[lst] != '(') ++lst;
	if (fir >= 1 && lst <= n) {
		int now = 0;
		for (int i = 1; i <= n; ++i)
			if (i < fir || i >= lst)
				now += pre[i] == mi + 1;
		if (now > ans)
			ans = now, ax = fir, ay = lst;
	}
	for (int i = 1; i <= n; ++i) if (pre[i] == mi + 1)
		fir = std::min(fir, i), lst = std::max(lst, i + 1);
	while (fir && buf[fir] != ')') --fir;
	while (lst <= n && buf[lst] != '(') ++lst;
	if (fir >= 1 && lst <= n) {
		int now = bse;
		for (int i = 1; i <= n; ++i)
			if (i < fir || i >= lst)
				now += pre[i] == mi + 2;
		if (now > ans)
			ans = now, ax = fir, ay = lst;
	}
	std::cout << ans << '\n' << ax << ' ' << ay << std::endl;
	return 0;
}