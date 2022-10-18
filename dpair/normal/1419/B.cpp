#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL sig[100005], base = 1, a[100005], l, r;
int main(){
	for (register int i = 1;i <= 30;i ++){
		r = i;
		a[i] = (a[i - 1] << 1) + base * base;
		base <<= 1;
		sig[i] = sig[i - 1] + a[i];
		if(sig[i] > 1000000000000000000) break;
	}
	int t;
	scanf("%d", &t);
	while(t --){
		LL n;scanf("%lld", &n);
		int L = 1, R = r, ans = 0;
		while(L <= R){
			int mid = (L + R) >> 1;
			if(sig[mid] <= n) ans = mid, L = mid + 1;
			else R = mid - 1;
		}
		printf("%d\n", ans);
	}
}