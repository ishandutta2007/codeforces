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
	int ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	for(i=2;i<=n;i++){
		ans += a[i] - a[i - 1] - 1; 
	}
	
	printf("%d\n", ans);
	
	return 0;
}