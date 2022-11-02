#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#define maxn 100009
using namespace std;
int n , a[maxn];
long long b[maxn], c[maxn];
long long sum[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n - 1; i++){
		b[i] = abs(a[i + 1] - a[i]);
	}
	n--;
	for(int i = 1; i <= n; i++){
		if(i & 1)
			c[i] = b[i];
		else
			c[i] = -b[i];
	}
	long long ans = 0;
	long long mi = 0;
	long long sum = 0;
	
	for(int i = 1; i <= n; i++){
		sum += c[i];
		ans = max(ans, sum - mi);
		if(i % 2 == 0)
			mi = min(mi, sum);
	}
	
	for(int i = 1; i <= n; i++){
		if(i & 1)
			c[i] = -b[i];
		else
			c[i] = b[i];
	}
	
	mi = c[1];
	sum = c[1];
	
	for(int i = 2; i <= n; i++){
		sum += c[i];
		ans = max(ans, sum - mi);
		if(i % 2 == 1){
			mi = min(mi, sum);
		}
	}
	
	cout << ans << endl;
	return 0;
}