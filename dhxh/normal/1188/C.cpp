#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int maxn = 1000 + 5;

int n, m;
long long f[maxn][maxn][2];
long long sum[maxn][maxn][2];
int a[maxn];
long long ans = 0;

int solve(int x){
	int i, j;
	int l = 0, r = 0;
	long long ret = 0;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			f[i][j][0] = f[i][j][1] = 0;
			sum[i][j][0] = sum[i][j][1] = 0;
		}
	}
	
	for(i=1;i<=n;i++){
		f[i][1][0] = 1;
		while(l + 1 < i and a[i] - a[l + 1] > x) l++;
		while(r + 1 < i and a[i] - a[r + 1] >= x) r++;
		
		for(j=1;j<m;j++){
			f[i][j + 1][0] = sum[l][j][0];
			f[i][j + 1][1] = (sum[r][j][0] - sum[l][j][0] + mod + sum[r][j][1]) % mod;
			sum[i][j][0] = (sum[i - 1][j][0] + f[i][j][0]) % mod;
			sum[i][j][1] = (sum[i - 1][j][1] + f[i][j][1]) % mod;
		}
		ret += f[i][m][1];
		if(ret >= mod) ret -= mod;
	}
	
	ans = (ans + ret * x) % mod;
	
	return 0;
}

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	a[0] = -1;
	for(i=0;a[1]+(m-1)*i<=1e5;i++){
		solve(i);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}