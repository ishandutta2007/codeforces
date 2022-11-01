#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];

int cnt[25];

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
		for(j=20;j>=0;j--){
			cnt[j] += ((a[i] >> j) & 1);
		}
	}
	
	long long ans = 0;
	for(i=1;i<=n;i++){
		long long x = 0;
		for(j=20;j>=0;j--){
			if(cnt[j] == 0) continue;
			cnt[j]--;
			x += (1 << j);
		}
		ans += x * x;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}