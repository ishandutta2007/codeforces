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
		for(j=-(i-2)*(i-1)/2;j<=(i-2)*(i-1)/2;j++){
			for(k=0;k<=(i-1);k++){
				f[i][j + N - (i - 1) + k] += f[i - 1][j + N];
				if(f[i][j + N - (i - 1) + k] >= mod) f[i][j + N - (i - 1) + k] -= mod;
				f[i][j + N + (i - 1) - k + 1] -= f[i - 1][j + N];
				if(f[i][j + N + (i - 1) - k + 1] < 0) f[i][j + N + (i - 1) - k + 1] += mod;
			}
		}
		
		for(j=-(i-1)*i/2;j<=(i-1)*i/2;j++){
			f[i][j + N] += f[i][j + N - 1];
			if(f[i][j + N] >= mod) f[i][j + N] -= mod;
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