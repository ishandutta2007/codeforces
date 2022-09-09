#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
vector <int> a[MAXN];
int main() {
	int n, m, k;
	read(n), read(k), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a[x % m].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		if (a[i].size() < k) continue;
		printf("Yes\n");
		for (int j = 0; j < k; j++)
			printf("%d ", a[i][j]);
		return 0;
	}
	printf("No\n");
	return 0;
}