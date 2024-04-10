#include <bits/stdc++.h>
using namespace std;

int a[100005], n;

int main(){
	scanf("%d", &n);
	for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d\n", (n - 1) >> 1);
	int l = 0, r = n + 1;
	for (register int i = 1;i <= n;i ++){
		if(i & 1) printf("%d ", a[-- r]);
		else printf("%d ", a[++ l]);
	}
	putchar(10);
	return 0;
}