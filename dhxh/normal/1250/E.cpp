#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int a[maxn];
int cnt[50];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int solve(){
	int i, j;
	if(n == 1){
		if(a[1] == 0){
			printf("DRAW\n");
		}else{
			printf("WIN\n");
		}
		return 0;
	}
	for(i=30;i>=0;i--){
		if(!(cnt[i] & 1)) continue;
		if((cnt[i] / 2 + 1) & 1){
			printf("WIN\n");
			return 0;
		}else{
			if((n - cnt[i]) & 1){
				printf("WIN\n");
			}else{
				printf("LOSE\n");
			}
			return 0;
		}
	}
	
	printf("DRAW\n");
	return 0;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		scanf("%d", &n);
		
		memset(cnt, 0, sizeof(cnt));
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			for(j=30;j>=0;j--){
				if((a[i] >> j) & 1) cnt[j]++;
			}
		}
		
		solve();
	}
	
	return 0;
}