#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];

int main(){
	int i, j;
	int x, y;
	
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	long long ans = 1ll * a[1] * (n - a[1] + 1);
	
	for(i=2;i<=n;i++){
		int x = a[i - 1], y = a[i];
		if(x == y)continue;
		if(x > y){
			ans += 1ll * (x - y) * y;
		}else{
			ans += 1ll * (y - x) * (n - y + 1);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}