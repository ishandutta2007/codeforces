#include <bits/stdc++.h>
using namespace std;

int a[100005], n;
int b[100005];
int main(){
	scanf("%d", &n);
	for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 0, r = n + 1, ans = 0;
	for (register int i = 1;i <= n;i ++){
		if(i & 1) b[i] = a[-- r];
		else b[i] = a[++ l];
	}
	for (register int i = 1;i <= n;i ++){
		if(i & 1) b[i] = a[r ++];
	}
	for (register int i = 2;i < n;i ++){
		if(b[i] < b[i + 1] && b[i] < b[i - 1]) ans ++;
	}
	printf("%d\n", ans);
	for (register int i = 1;i <= n;i ++) printf("%d ", b[i]);
	putchar(10);
	return 0;
}