#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 300005;

int n, tp, ans[N]; string ss, tt; int firid, mx, mn;

struct FenWick {
	int tg[N];
	
	void init(int n) {
		for (int i = 1; i <= n; i++) tg[i] = 0;
	}
	void modify(int x) {
		for (int i = x; i <= n; i += (i & -i)) tg[i] ^= 1;
	}
	int ask(int x) {
		int ret = 0;
		for (int i = x; i >= 1; i -= (i & -i)) ret ^= tg[i];
		return ret;
	}
} fwk;

char get(int x) {
	int tt; if (firid == mn) tt = mn + x - 1; else tt = mx - x + 1;
	if (fwk.ask(tt)) return (ss[tt] == '1' ? '0' : '1');
	return ss[tt];
}

int main() {
	int T = read();
	while (T--) {
		n = read(); cin >> ss; cin >> tt;
		ss = '$' + ss; tt = '$' + tt; tp = 0;
		firid = 1, mx = n, mn = 1; fwk.init(n);
		for (int i = n; i >= 1; i--)
			if (get(i) != tt[i]) {
				if (get(1) == tt[i]) ans[++tp] = 1, fwk.modify(firid), fwk.modify(firid + 1);
				fwk.modify(mn), fwk.modify(mx + 1);
				if (firid == mn) mn++, firid = mx; else mx--, firid = mn;
				ans[++tp] = i;
			} else {
				if (firid == mn) mx--; else mn++;
			}
		printf("%d\n", tp);
		for (int i = 1; i <= tp; i++) printf("%d%c", ans[i], " \n" [i == tp]);
	}
	return 0;
}