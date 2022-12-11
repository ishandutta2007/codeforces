#include <bits/stdc++.h>

const int MAXN = 500010;
int A, B, n;
char buf[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> A >> B >> buf + 1; n = strlen(buf + 1);
		buf[0] = buf[n + 1] = 'X';
		bool flg = false;
		int lst = 0, cnt = 0, cx = 0, free = false;
		for (int i = 1; i <= n + 1 && !flg; ++i)
			if (buf[i] == 'X') {
				int l = i - lst - 1;
				if (B <= l && l < A) flg = true;
				if (A <= l && l < B * 2) cnt ^= 1;
				if (B * 2 <= l) {
					if (cx) flg = true;
					else cx = l;
				}
				lst = i;
			}
		if (!flg) {
			 if (!cx) flg = cnt ^ 1;
			 else {
				 bool can = false;
				 for (int sp = 1; !can && sp + A - 1 <= cx; ++sp) {
					 int l = sp - 1, r = cx - sp - A + 1;
					 if ((B <= l && l < A) || B * 2 <= l) continue;
					 if ((B <= r && r < A) || B * 2 <= r) continue;
					 int dd = cnt;
					 if (A <= l) dd ^= 1;
					 if (A <= r) dd ^= 1;
					 if (dd == 0) can = true;
				 }
				 flg = !can;
			 }
		}
		std::cout << (flg ? "NO" : "YES") << '\n';
	}
	return 0;
}