#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
char s[300005];
int main(){
	int t;scanf("%d", &t);
	while(t --){
		scanf("%d%d", &n, &k);
		for (register int i = 0;i < k;i ++) c[i] = -1;
		scanf("%s", s + 1);
		bool ck = 1;
		for (register int i = 1;i <= n;i ++){
			if(s[i] == '1'){
				if(c[i % k] == 0){
					ck = 0;
					break;
				}
				c[i % k] = 1;
			}
			if(s[i] == '0'){
				if(c[i % k] == 1){
					ck = 0;
					break;
				}
				c[i % k] = 0;
			}
		}
		int cnt = 0, num = 0;
		if(!ck) {printf("NO\n");continue;}
		for (register int i = 0;i < k;i ++){
			if(~c[i]) num += c[i];
			else cnt ++;
		}
		if(num > (k >> 1)){
			printf("NO\n");
			continue;
		}
		if(num + cnt >= (k >> 1)){
			printf("YES\n");
		}
		else printf("NO\n");
	}
}