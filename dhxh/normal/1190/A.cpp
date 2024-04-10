#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
const int maxn = 1e5 + 5;
 
long long n, m, t, k;
 
long long a[maxn];
 
int read(){
	int x;
	scanf("%d", &x);
	return x;
}
 
int main(){
	int i, j;
	long long x = 0, y = 0;
	long long ans = 0;
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for(i=1;i<=m;i++){
		scanf("%lld", &a[i]);
		a[i]--;
	}
	
	for(i=1;i<=m;i+=j){
		if(a[i] - y + x >= k){
			y += k - x;
			x = 0;
		}
		y += (a[i] - y) / k * k;
		ans++;
		for(j=0;j+i<=m;j++){
			if(a[i + j] >= y + k - x){
				break;
			}
		}
		x = (a[i + j - 1] - y - j + x + k) % k;
		y = a[i + j - 1];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}