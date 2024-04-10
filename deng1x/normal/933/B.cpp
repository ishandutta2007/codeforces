#include <bits/stdc++.h>

#define ll long long
#define MAXN (2010)

ll p, k;
int a[MAXN];

int main(){
	scanf("%I64d%I64d", &p, &k);
	int d = 0, x;
	while (p){
		x = (d & 1) ? (k - p % k) % k : p % k;
		p += (d & 1) ? x : -x;
		a[d ++] = x;
		p /= k;
	}
	printf("%d\n", d);
	for (int i = 0; i < d; ++ i){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}