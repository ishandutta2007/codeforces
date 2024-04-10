#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

long long inf = 0x3f3f3f3f3f3f3f3f;

char str[maxn];
long long a[maxn];

char c[] = {0, 'h', 'a', 'r', 'd'};

long long f[maxn][6];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long ans = inf;
	
	memset(f, 0x3f, sizeof(f));
	
	n = read();
	
	scanf("%s", &str[1]);
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	f[0][0] = 0;
	
	for(i=1;i<=n;i++){
		for(j=0;j<=4;j++){
			f[i][j] = f[i - 1][j];
		}
		
		for(j=1;j<=4;j++){
			if(str[i] == c[j]){
				f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]);
				f[i][j - 1] = f[i - 1][j - 1] + a[i];
				break;
			}
		}
	}
	
	if(f[n][4] == inf){
		ans = 0;
	}
	
	for(i=0;i<4;i++){
		ans = min(ans, f[n][i]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}