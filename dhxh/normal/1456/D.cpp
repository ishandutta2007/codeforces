#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 5;

int n;

long long t[maxn];
long long a[maxn];

long long f[maxn][maxn];

int main(){
	int i, j, k;
	
	scanf("%d", &n);
	
	memset(f, 0x3f, sizeof(f));
	
	for(i=1;i<=n;i++){
		scanf("%lld%lld", &t[i], &a[i]);
	}
	
	f[0][0] = 0;
	
	for(i=0;i<n;i++){
		for(j=i;j<=n;j++){
			if(i == j){
				for(k=i+1;k<=n;k++){
					long long dis = abs(a[i] - a[k]);
					if(max(f[i][j] + dis, t[i]) + abs(a[k] - a[i + 1]) <= t[i + 1]){
						f[i + 1][k] = min(f[i + 1][k], max(f[i][j] + dis, t[i]) + abs(a[k] - a[i + 1]));
					}
				}
			}else if(j == i + 1){
				for(k=i+2;k<=n;k++){
					long long dis = abs(a[i] - a[k]);
					long long s = max(f[i][j], t[i]);
					if(max(s + dis, t[i + 1]) + abs(a[k] - a[i + 2]) <= t[i + 2]){
						f[i + 2][k] = min(f[i + 2][k], max(s + dis, t[i + 1]) + abs(a[k] - a[i + 2]));
					}
				}
			}else{
				if(max(f[i][j], t[i]) + abs(a[i] - a[i + 1]) <= t[i + 1]){
					f[i + 1][j] = min(f[i + 1][j], max(f[i][j], t[i]) + abs(a[i] - a[i + 1]));
				}
			}
		}
	}
	
	if(f[n][n] <= t[n] or f[n - 1][n] <= t[n]){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
}