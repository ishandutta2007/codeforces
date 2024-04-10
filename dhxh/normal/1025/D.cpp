#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 700 + 5;

int n, m;

int a[maxn];

bool b[maxn][maxn];

bool f[maxn][maxn][2];
bool v[maxn][maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int l, int r, int x){
	int i, j;
	
	if(r < l){
		v[l][r][x] = true;
		f[l][r][x] = true;
		return true;
	}
	if(v[l][r][x]){
		return f[l][r][x];
	}
	
	v[l][r][x] = true;
	
	if(x == 0){
		for(i=l;i<=r;i++){
			if(b[i][l - 1]){
				dfs(l, i - 1, 1);
				dfs(i + 1, r, 0);
				f[l][r][x] = f[l][r][x] | (f[l][i - 1][1] & f[i + 1][r][0]);
				if(f[l][r][x]){
				    break;
			    }
			}
		}
	}else{
		for(i=l;i<=r;i++){
			if(b[i][r + 1]){
				dfs(l, i - 1, 1);
				dfs(i + 1, r, 0);
				f[l][r][x] = f[l][r][x] | (f[l][i - 1][1] & f[i + 1][r][0]);
				if(f[l][r][x]){
			    	break;
			    }
			}
		}
	}
	
	return f[l][r][x];
}

int gcd(int x, int y){
	if(x % y){
		return gcd(y, x % y);
	}else{
		return y;
	}
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		b[0][i] = b[i][0] = true;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i == j){
				continue;
			}
			b[i][j] = (gcd(a[i], a[j]) > 1);
		}
	}
	
	dfs(1, n, 0);
	
	if(f[1][n][0]){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
}