#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 5;
const int N = maxn * maxn / 2;
int mod;

int n;

pair <int, int> a[maxn];

int f[maxn][maxn * maxn];

long long ans = 0;

int main(){
	int i, j, k;
	char ch;
	int x, y;
	
	scanf("%d%d", &n, &mod);
	
	f[1][N] = 1;
	for(i=2;i<=n;i++){
		long long sum = 0, sa = 0, sb = 0;
		
		for(j=1;j<=(i-1);j++){
			sum = (sum + 1ll * (i - j) * f[i - 1][-(i - 1) * i / 2 + j + N]) % mod;
			sb = (sb + f[i - 1][-(i - 1) * i / 2 + j + N]) % mod;
		}
		
		for(j=0;j<=(i-1);j++){
			sum = (sum + 1ll * (i - j) * f[i - 1][-(i - 1) * i / 2 - j + N]) % mod;
			sa = (sa + f[i - 1][-(i - 1) * i / 2 - j + N]) % mod;
		}
		
		for(j=-(i-1)*i/2;j<=(i-1)*i/2;j++){
			f[i][j + N] += sum;
			if(f[i][j + N] >= mod) f[i][j + N] -= mod;
			sum -= sa;
			if(sum < 0) sum += mod;
			sa = (sa + f[i - 1][j + 1 + N] - f[i - 1][j - i + 1 + N] + mod) % mod;
			sb = (sb - f[i - 1][j + N] + f[i - 1][j + i + N] + mod) % mod;
			sum += sb;
			if(sum >= mod) sum -= mod;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=-(i-1)*i/2;j<=(i-1)*i/2;j++){
			f[i][j + N] += f[i][j + N - 1];
			if(f[i][j + N] >= mod) f[i][j + N] -= mod;
		}
	}
	
	long long sum = 1;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			long long c = n - i + 1 - j;
			if(j >= (n - i) * (n - i - 1) / 2) continue;
			ans = (ans + sum * c % mod * (f[n - i][(n - i) * (n - i - 1) / 2 + N] - f[n - i][j + N] + mod)) % mod;
		}
		sum = sum * (n - i + 1) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}