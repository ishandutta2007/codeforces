#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 5;
const int mod = 1e9 + 7;

int n, m, t;

long long a[maxn];
long long f[maxn][maxn];

long long sum[maxn];

int main(){
	int i, j;
	
	scanf("%d%d%d", &n, &m, &t);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=1;i<=n;i++){
		f[0][i] = 1;
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
			if(f[i][j] >= mod) f[i][j] -= mod;
		}
	}
	for(i=0;i<=m;i++){
		for(j=1;j<=n;j++){
			sum[j] = (sum[j] + f[i][j] * f[m - i][j]) % mod;
		}
	}
	
	long long ans = 0;
	
	for(i=1;i<=n;i++){
		ans = (ans + sum[i] * a[i]) % mod;
	}
	
	while(t--){
		int p;
		long long x;
		scanf("%d%lld", &p, &x);
		ans -= sum[p] * a[p] % mod; 
		if(ans < 0) ans += mod;
		a[p] = x;
		ans = (ans + sum[p] * a[p]) % mod;
		printf("%lld\n", ans);
	}
	
	return 0;
}