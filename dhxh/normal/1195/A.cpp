#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int cnt[1005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	int ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		x = read();
		cnt[x]++;
	}
	
	x = 0;
	for(i=1;i<=m;i++){
		ans += (cnt[i] / 2) * 2;
		x += cnt[i] % 2;
	}
	
	ans += x / 2 + x % 2;
	
	printf("%d\n", ans);
	
	return 0;
}