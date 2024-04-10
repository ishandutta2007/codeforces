#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 105;

int n, m, t;

int a[maxn];
int cnt[maxn];

long long f[2][maxn][maxn * maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k, l;
	int ans = 0;
	int sum = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(!cnt[a[i]]){
			m++;
		}
		sum += a[i];
		cnt[a[i]]++;
	}
	
	if(m == 2){
		printf("%d\n", n);
		return 0;
	}
	
	f[0][0][0] = 1;
	
	for(i=1;i<=100;i++){
		for(k=0;k<=n;k++){
			for(j=0;j<=10000;j++){
				f[i & 1][k][j] = f[(i - 1) & 1][k][j];
			}
		}
		for(l=1;l<=cnt[i];l++){
			for(k=0;k<=n-l;k++){
				for(j=0;j<=10000-i*l;j++){
					f[i & 1][k + l][j + i * l] += f[(i - 1) & 1][k][j];
				}
			}
		}
	}
	
	for(i=1;i<=100;i++){
		for(j=1;j<=cnt[i];j++){
			if(f[n & 1][j][j * i] == 1){
				ans = max(ans, j);
			}
			if(f[n & 1][n - j][sum - j * i] == 1){
				ans = max(ans, j);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}