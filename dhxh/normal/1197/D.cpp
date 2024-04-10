#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n, m;
long long k;

long long a[maxn];
long long f[maxn][15];
long long inf = 0x3f3f3f3f3f3f3f3f;

int main(){
	int i, j;
	long long ans = 0;
	
	scanf("%d%d%lld", &n, &m, &k);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			f[i][j] = -inf;
		}
	}
	
	for(i=1;i<=n;i++){
		f[i][1] = max(f[i - 1][m] + a[i] - k, a[i] - k);
		ans = max(ans, f[i][1]);
		for(j=2;j<=m;j++){
			f[i][j] = f[i - 1][j - 1] + a[i];
			ans = max(ans, f[i][j]);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}