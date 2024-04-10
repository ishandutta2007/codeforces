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

int a[maxn];
int b[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		m = read();
		
		for(i=1;i<=n;i++){
			a[i] = read();
		}
		
		for(i=1;i<=m;i++){
			b[i] = read();
		}
		
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + m + 1);
		
		long long ans = 0;
		
		for(i=1;i<=m;i++){
			ans += a[i];
			if(b[i] == 1) ans += a[i];
		}
		
		j = m;
		for(i=1;i<=m;i++){
			if(b[i] == 1) continue;
			j += b[i] - 1;
			ans += a[j];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}