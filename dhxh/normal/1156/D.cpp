#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

vector <int> e[maxn];
vector <int> w[maxn];

long long f[maxn][2];
long long g[maxn][2];
long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int fa){
	for(int i=0;i<e[x].size();i++){
		int y = e[x][i];
		int c = w[x][i];
		if(y != fa){
			dfs(y, x);
			if(c){
				f[x][1] += f[y][0] + f[y][1] + 1;
				g[x][1] += g[y][1] + 1;
			}else{
				f[x][0] += f[y][0] + 1;
				g[x][0] += g[y][0] + g[y][1] + 1;
			}
		}
	}
	
	ans += f[x][0] + f[x][1] + g[x][0] + g[x][1];
	
	for(int i=0;i<e[x].size();i++){
		int y = e[x][i];
		int c = w[x][i];
		if(y != fa){
			if(c){
				ans += (f[y][0] + f[y][1] + 1) * (g[x][1] - (g[y][1] + 1));
			}else{
				ans += (f[y][0] + 1) * (g[x][0] - (g[y][0] + g[y][1] + 1) + g[x][1]);
			}
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y, c;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		c = read();
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(c);
		w[y].push_back(c);
	}
	
	dfs(1, -1);
	
	printf("%lld\n", ans);
	
	return 0;
}