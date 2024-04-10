#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
inline char readchar() {
	char c = getchar();
	while (c < 'a' || c > 'z') c = getchar();
	return c;
}

const int N = 100005;

int n;
char str[N], nowstr[N];
bitset<N> v[26], ans;

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++) v[str[i] - 'a'].set(i, 1);
	int T = read();
	while (T--) {
		int opt = read();
		if (opt == 1) {
			int x = read(); char nc = readchar();
			if (str[x] != nc)
				v[nc - 'a'].set(x, 1), 
				v[str[x] - 'a'].set(x, 0), 
				str[x] = nc;
		} else {
			int l = read(), r = read();
			scanf("%s", nowstr + 1);
			int sl = strlen(nowstr + 1);
			ans.set();
			// for (int i = 1; i <= 10; i++) printf("%d", (int)ans[i]);
			// printf("\n");
			for (int i = 1; i <= sl; i++)
				ans &= (v[nowstr[i] - 'a'] >> (i - 1));
			int lc = (ans >> l).count(), rc = (ans >> (r - sl + 2)).count();
			if (lc < rc) printf("0\n");
			else printf("%d\n", lc - rc);
		} 
	}
	return 0;
}