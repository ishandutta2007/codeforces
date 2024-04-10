#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n;
char s[MAXN], t[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		scanf("\n%s", s + 1);
		scanf("\n%s", t + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] > t[i]) ans = -1;
		if (ans == -1) {
			puts("-1");
			continue;
		}
		while (true) {
			char c = 'z', d = 'z';
			for (int i = 1; i <= n; i++)
				if (s[i] < t[i]) {
					if (s[i] < c) {
						c = s[i];
						d = t[i];
					} else if (s[i] == c) chkmin(d, t[i]);
				}
			if (c == 'z') break; ans++;
			for (int i = 1; i <= n; i++)
				if (s[i] < t[i] && s[i] == c) s[i] = d;
		}
		printf("%d\n", ans);
	}
	return 0;
}