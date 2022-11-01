#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int n, m, t;

int b[maxn][maxn];
int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(int x){
	int i, j;
	
	a[1] = x;
	for(i=2;i<=n;i++){
		a[i] = b[1][i] / x;
	}
	
	for(i=2;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(b[i][j] != 1ll * a[i] * a[j])return false;
		}
	}
	
	return true;
}

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &b[i][j]);
		}
	}
	
	int g = b[1][2];
	
	for(i=3;i<=n;i++){
		g = __gcd(g, b[1][i]);
	}
	
	for(i=1;i*i<=g;i++){
		if(g % i == 0){
			if(check(i)){
				break;
			}
			if(check(g / i)){
				break;
			}
		}
	}
	
	for(i=1;i<=n;i++)printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}