#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int n, cnt[105];
LL a[100005];
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (register int i = 1;i <= n;i ++) scanf("%lld", &a[i]), cnt[a[i]] ++;
		LL ans = 0, it = 0;
		while(cnt[it]) cnt[it] --, it ++;
		ans += it;it = 0;
		while(cnt[it]) cnt[it] --, it ++;
		ans += it;
		printf("%lld\n", ans);
		
	}
}