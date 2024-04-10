#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int n;
LL a[100005];
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for (register int i = 1;i <= n;i ++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		printf("%lld\n", max(a[n] * a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4], max(a[n] * a[n - 1] * a[n - 2] * a[1] * a[2], a[n] * a[1] * a[2] * a[3] * a[4])));
	}
}