#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 5;

int n, m, t;

int a[maxn];
int ans[maxn];
int cnt[maxn * 4];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = a[i - 1] + (i - 1) / 2;
	}
	
	if(a[n] < m){
		printf("-1\n");
		return 0;
	}
	
	for(i=1;i<=n;i++){
		if(a[i] >= m){
			x = i - 1;
			break;
		}
	}
	
	for(i=1;i<=x;i++) ans[i] = i;
	
	m -= a[x];
	
	for(i=1;i<=x;i++){
		for(j=x;j>i;j--){
			if(i + j <= x) break;
			cnt[i + j]++;
		}
	}
	
	for(i=x+1;i<=2*x;i++){
		if(cnt[i] == m){
			ans[++x] = i;
			break;
		}
	}
	
	x = n - x;
	
	while(x--){
		ans[n - x] = 100000000 - x * 10000;
	}
	
	for(i=1;i<=n;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}