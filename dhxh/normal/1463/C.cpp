#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, T;

long long a[maxn];
long long b[maxn];

int main(){
	int i, j;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d", &n);
		long long t = 0;
		long long p = 0;
		long long d = 0;
		int ans = 0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld", &a[i], &b[i]);
		}
		
		a[n + 1] = 1e18;
		
		for(i=1;i<=n;i++){
			if(t + abs(d - p) <= a[i]){
				p = d;
				d = b[i];
				t = a[i];
			}
			
			if(p <= d and p <= b[i] and b[i] <= d){
				if(a[i] <= b[i] - p + t and b[i] - p + t <= a[i + 1]){
					ans++;
				}
			}else if(p >= d and d <= b[i] and b[i] <= p){
				if(a[i] <= abs(b[i] - p) + t and abs(b[i] - p) + t <= a[i + 1]){
					ans++;
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}