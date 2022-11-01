#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

char str[55];

int main() {
	int T = read();
	while (T--) {
		int n = read(), res = 0, ans = 0;
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++)
			if (str[i] == '(') res++;
			else {
				if (res == 0) ans++; else res--;
			}
		printf("%d\n", ans);
	}
	return 0;
}