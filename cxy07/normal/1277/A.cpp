//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n,tmp,cnt;
int ans = 0;

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		ans = 0;
		for(register int i = 1,now = 0;i <= 9; ++i) {
			now = 0;
			(now *= 10) += i;
			while(now <= n) {
				ans++;
				(now *= 10) += i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}