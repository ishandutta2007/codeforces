#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a[1005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	int ans = 10000;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		x = read();
		a[x]++;
	}
	
	for(i=0;i<=100;i++){
		int tmp = 0;
		for(j=0;j<=m;j++){
			tmp += a[i + j];
		}
		
		ans = min(ans, n - tmp);
	}
	
	printf("%d\n", ans);
	
	
	return 0;
}