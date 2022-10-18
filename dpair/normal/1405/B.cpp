#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	int t;scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for (register int i = 1;i <= n;i ++)scanf("%d", &a[i]);
		long long ans = 0, num = 0;
		for (register int i = 1;i <= n;i ++){
			num += a[i];
			if(num < 0){
				ans -= num;
				num = 0;
			}
		}
		printf("%lld\n", ans);
	}
}