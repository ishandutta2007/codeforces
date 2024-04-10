#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t, k;

int ans = 0;

char a[2005][2005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	k = read();
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf(" %c", &a[i][j]);
		}
	}
	
	for(i=1;i<=n;i++){
		int cnt = 0;
		for(j=1;j<=m;j++){
			if(a[i][j] == '.'){
				cnt++;
			}else{
				cnt = 0;
			}
			if(cnt >= k){
				ans++;
			}
		}
	}
	
	for(j=1;j<=m;j++){
		int cnt = 0;
		for(i=1;i<=n;i++){
			if(a[i][j] == '.'){
				cnt++;
			}else{
				cnt = 0;
			}
			if(cnt >= k){
				ans++;
			}
		}
	}
	
	if(k == 1){
		ans /= 2;
	}
	
	printf("%d\n", ans);
	
	return 0;
}