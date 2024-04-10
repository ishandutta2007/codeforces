#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int inf = 0x3f3f3f3f;

int n, m;

string str;

int f[505][505][30];

int dfs(int l, int r, int x){
	int i, j;
	
	if(l == r){
		return 0;
	}
	
	if(x == 0){
		for(i=1;i<=26;i++){
			if(f[l][r][i] >= inf){
				dfs(l, r, i);
			}
			f[l][r][x] = min(f[l][r][x], f[l][r][i] + 1);
		}
	}else{
		for(i=l;i<r;i++){
			if(f[l][i][x] >= inf){
				dfs(l, i, x);
			}
			if(f[l][i][0] >= inf){
				dfs(l, i, 0);
			}
			if(f[i + 1][r][x] >= inf){
				dfs(i + 1, r, x);
			}
			if(f[i + 1][r][0] >= inf){
				dfs(i + 1, r, 0);
			}
			f[l][r][x] = min(f[l][r][x], min(f[l][i][x], f[l][i][0]) + min(f[i + 1][r][x], f[i + 1][r][0]));
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	
	cin >> n;
	cin >> str;
	
	memset(f, 0x3f, sizeof(f));
	
	for(i=0;i<n;i++){
		f[i + 1][i + 1][str[i] - 'a' + 1] = 0;
		f[i + 1][i + 1][0] = 1;
	}
	
	dfs(1, n, 0);
	
	cout << f[1][n][0] << endl;
	
	return 0;
}