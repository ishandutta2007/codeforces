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

int ans = 1e9;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=2;i<=n;i++){
		ans = min(ans, max(a[i - 1] - 1, (int)1e6 - a[i]));
	}
	
	ans = min(ans, min(a[n] - 1, (int)1e6 - a[1]));
	
	printf("%d\n", ans);
	
	return 0;
}