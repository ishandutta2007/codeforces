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

int n, tp, ans[N]; string ss, tt;

void flip(int pos) {
	ans[++tp] = pos;
	for (int i = 1; i <= pos; i++) ss[i] = (ss[i] == '0' ? '1' : '0');
	for (int i = 1; i <= (pos >> 1); i++) swap(ss[i], ss[pos - i + 1]);
}

int main() {
	int T = read();
	while (T--) {
		n = read(); cin >> ss; cin >> tt;
		ss = '$' + ss; tt = '$' + tt; tp = 0;
		for (int i = n; i >= 1; i--)
			if (ss[i] != tt[i]) {
				char fir = ss[1];
				if (ss[1] == tt[i]) flip(1);
				flip(i);
			}
		printf("%d\n", tp);
		for (int i = 1; i <= tp; i++) printf("%d%c", ans[i], " \n" [i == tp]);
	}
	return 0;
}