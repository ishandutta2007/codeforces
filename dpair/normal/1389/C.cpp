#include <bits/stdc++.h>
using namespace std;
char s[200010];
int cnt[10];
bool vis[10];
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		int ans = -1;
		for (register int i = 1;i <= len;i ++){
			cnt[s[i] - 48] ++;
		}
		for (register int i = 0;i <= 9;i ++) ans = max(ans, cnt[i]);
		for (register int i = 0;i <= 9;i ++){
			memset(cnt, 0, sizeof(cnt));
			memset(vis, 0, sizeof(vis));
			for (register int j = 1;j <= len;j ++){
				if(s[j] - 48 == i){
					for (register int k = 0;k <= 9;k ++){
						if(vis[k]){
							cnt[k] ++;
							vis[k] = 0;
						}
					}
				}
				else vis[s[j] - 48] = 1;
			}
			for (register int j = 0;j <= 9;j ++){
				if(j ^ i) ans = max(ans, cnt[j] * 2);
			}
		}
		printf("%d\n", len - ans);
	}
}