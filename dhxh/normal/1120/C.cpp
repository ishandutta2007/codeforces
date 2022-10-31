#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 5000 + 5;

int n, m, t;
int a, b;

char str[maxn];

int f[maxn];

int g[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	a = read();
	b = read();
	
	for(i=1;i<=n;i++){
		scanf(" %c", &str[i]);
	}
	
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(str[j] == str[i]){
				g[i][j] = g[i - 1][j - 1] + 1;
			}
		}
	}
	
	f[0] = 0;
	
	for(i=1;i<=n;i++){
		f[i] = f[i - 1] + a;
		for(j=1;j<=i;j++){
			int t = min(i - j, g[j][i]);
			if(t){
				f[i] = min(f[i], f[i - t] + b);
			}
			
		}
	}
	
	printf("%d\n", f[n]);
	
	return 0;
}