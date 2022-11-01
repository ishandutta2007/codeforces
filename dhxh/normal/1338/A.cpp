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

long long a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		
		for(i=1;i<=n;i++){
			a[i] = read();
		}
		
		long long mx = a[1];
		long long z = 0;
		
		for(i=2;i<=n;i++){
			if(mx > a[i]){
				z = max(z, mx - a[i]);
			}
			mx = max(mx, a[i]);
		}
		
		long long ans = 0;
		while((1ll << ans) <= z){
			ans++;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}