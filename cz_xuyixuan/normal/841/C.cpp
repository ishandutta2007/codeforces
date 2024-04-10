#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
struct info {int value, home; };
info a[MAXN], b[MAXN];
bool cmpb(info x, info y) {
	return x.value < y.value;
}
bool cmpa(info x, info y) {
	return x.value > y.value;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].value);
		a[i].home = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i].value);
		b[i].home = i;
	}
	sort(a + 1, a + n + 1, cmpa);
	sort(b + 1, b + n + 1, cmpb);
	static int ans[MAXN];
	for (int i = 1; i <= n; i++)
		ans[b[i].home] = a[i].value;
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}