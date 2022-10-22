#include <bits/stdc++.h>

int main(){
	int q;
	scanf("%d", &q);
	while(q --){
		int n;
		scanf("%d", &n);
		if(n < 4){
			printf("-1\n");
			continue;
		}
		if(n % 4 == 0){
			printf("%d\n", n / 4);
			continue;
		}
		if(n % 4 == 1){
			int ans = 1;
			n -= 9;
			if(n < 0) ans = -1;
			else ans += n / 4;
			printf("%d\n", ans);
			continue;
		}
		if(n % 4 == 2){
			int ans = 1;
			n -= 6;
			if(n < 0) ans = -1;
			else ans += n / 4;
			printf("%d\n", ans);
			continue;
		}
		if(n % 4 == 3){
			int ans = 2;
			n -= 15;
			if(n < 0) ans = -1;
			else ans += n / 4;
			printf("%d\n", ans);
			continue;
		}
	}
	return 0;
}