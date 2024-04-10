#include <bits/stdc++.h>

#define MAXN (1010)

int a[MAXN];

int main(){
	for(int i = 0; i < MAXN; ++ i){
		a[i] = i * (i - 1) / 2;
	}
	int k;
	scanf("%d", &k);
	if(!k){
		printf("a\n");
		return 0;
	}
	std::string ans;
	int now = 0;
	while(k){
		int x = std::upper_bound(a, a + MAXN, k) - a - 1;
		for(int i = 1; i <= x; ++ i){
			ans += 'a' + now;
		}
		++ now;
		k -= a[x];
	}
	std::cout << ans << std::endl;
	return 0; 
}