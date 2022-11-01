#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

int u, v;

int a[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d%d", &n, &u, &v);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		
		bool flag = false;
		bool f = false;
		
		for(i=2;i<=n;i++){
			if(abs(a[i] - a[i - 1]) >= 2){
				flag = true;
			}
			
			if(abs(a[i] - a[i - 1]) >= 1){
				f = true;
			}
		}
		
		long long ans = 0x3f3f3f3f3f3f3f3f;
		
		if(flag){
			printf("%d\n", 0);
			continue;
		}
		
		if(f) ans = u;
		else ans = u + v;
		
		for(i=2;i<=n;i++){
			for(j=a[i]-5;j<=a[i]+5;j++){
				if(abs(j - a[i - 1]) >= 2){
					ans = min(ans, 1ll * v * abs(j - a[i]));
				}
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}