#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int a[110];
int cnt[110];
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
		for (register int s = 1;s <= (n << 1);s ++){
			memset(cnt, 0, sizeof(cnt));
			int num = 0;
			for (register int i = 1;i <= n;i ++){
				cnt[a[i]] ++;
			}
			for (register int i = 1;i <= n;i ++){
				if(s - a[i] <= 0) continue;
				if(a[i] == s - a[i]){
					if(cnt[a[i]] >= 2){
						cnt[a[i]] -= 2;
						num ++;
					}
					continue;
				}
				if(cnt[a[i]] && cnt[s - a[i]])
				{
					cnt[a[i]] --;
					cnt[s - a[i]] --;
					num ++;
				}
			}
			ans = max(ans, num);
		}
		printf("%d\n", ans);
	}
}