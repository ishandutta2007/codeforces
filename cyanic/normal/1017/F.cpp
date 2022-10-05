%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define rep(i,a,b) for (register ui i=(a); i<=(b); i++)
#define per(i,a,b) for (register ui i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned char uc;

uc b[10000005];
ui p[18005], n, A, B, C, D, cnt, S, ans, x, y;

void update(ui x) {
	b[x>>3] |= 1 << (x & 7);
}

bool query(ui x) {
	return b[x>>3] >> (x & 7) & 1;
}

ui cur[30], tmp, tmp2;
void mark(ui x) {
	tmp = x % 30; tmp2 = x / 30 * 8;
	if (cur[tmp] != 233) update(tmp2 + cur[tmp]);
}

bool check(ui x) {
	tmp = x % 30; tmp2 = x / 30 * 8;
	if (cur[tmp] != 233) return !query(tmp2 + cur[tmp]);
	return 0;
}

ui ttt;

int main() {
	rep (i, 0, 29) cur[i] = 233;
	cur[1] = 0; cur[7] = 1;
	cur[11] = 2; cur[13] = 3;
	cur[17] = 4; cur[19] = 5;
	cur[23] = 6, cur[29] = 7;
	cin >> n >> A >> B >> C >> D;
	if (n <= 5) S = 5;
	else S = sqrt(n) + 2;
	rep (i, 2, n) {
		if (i == 2 || i == 3 || i == 5 || check(i)) {
			// printf("%d\n", i);
			if (i <= S) p[++cnt] = i;
			ttt = 0; x = n / i;
			while (x) {
				ttt = ttt + x;
				x /= i;
			}
			ans = ans + ttt * (i * i * i * A + i * i * B + i * C + D);
		}
		for (ui j = 1; j <= cnt && p[j] * i <= n; j++) {
			mark(i * p[j]);
			if (i % p[j] == 0) break;
		}
	}
	cout << ans;
	return 0;
}