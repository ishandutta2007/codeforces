#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
long long a[110], b[110], mina, minb, ans; 
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		scanf("%d", &n);
		mina = minb = 0x3f3f3f3f3f3f3f3f;
		for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]), mina = min(mina, a[i]);
		for (register int i = 1;i <= n;i ++) scanf("%d", &b[i]), minb = min(minb, b[i]);
		ans = 0;
		for (register int i = 1;i <= n;i ++){
			ans += max(a[i] - mina, b[i] - minb);
		}
		printf("%lld\n", ans);
	}
}