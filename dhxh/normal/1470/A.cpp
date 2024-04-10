#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, t;

int a[maxn];
long long c[maxn];

void solve(){
	long long ans = 0x3f3f3f3f3f3f3f3f;
	int i, j = 1;
	
	for(i=1;i<=n;i++){
		if(j <= a[i]){
			j++;
		}
	}
	
	int z = j - 1;
	long long sum = 0;
	
	for(i=1;i<=z;i++){
		sum += c[i];
	}
	
	for(i=1;i<=n-z;i++){
		sum += c[a[i]];
	}
	
	ans = sum;
	
	for(i=z-1;i>=0;i--){
		sum -= c[i + 1];
		sum += c[a[n - i]];
		ans = min(ans, sum);
	}
	
	printf("%lld\n", ans);
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		
		for(i=1;i<=m;i++){
			scanf("%lld", &c[i]);
		}
		
		sort(a + 1, a + n + 1);
		
		solve();
	}
	
	return 0;
}