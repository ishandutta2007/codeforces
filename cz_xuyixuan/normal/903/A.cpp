#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		if (n % 3 == 0) printf("YES\n");
		else if (n % 3 == 1) printf(n >= 7 ? "YES\n" : "NO\n");
		else printf(n >= 14 ? "YES\n" : "NO\n");
	}
	return 0;
}