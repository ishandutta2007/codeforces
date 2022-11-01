#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

long long a[maxn];

long long ans = 1e18 + 1;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=2*n;i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 2 * n + 1);
	
	ans = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
	
	for(i=0;i<n;i++){
		ans = min(ans, (a[n + i] - a[i + 1]) * (a[2 * n] - a[1]));
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}