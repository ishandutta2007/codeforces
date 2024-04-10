#include<bits/stdc++.h>
using namespace std;
#define MAXN	300005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool mark[MAXN];
int main() {
	int n; read(n);
	int pos = n;
	printf("1 ");
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		mark[x] = true;
		while (mark[pos]) pos--;
		printf("%d ", pos - (n - i) + 1);
	}
	return 0;
}