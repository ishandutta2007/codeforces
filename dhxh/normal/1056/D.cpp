#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int fa[maxn];

vector <int> e[maxn];

int w[maxn];
int f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x){
	int y;
	
	if(e[x].size() == 0){
		f[x] = 1;
	}
	
	for(auto y : e[x]){
		dfs(y);
		f[x] += f[y];
	}
	
	w[f[x]]++;
	
	return 0;
}

int main(){
	int i, j = 0;
	int sum = 0;
	
	n = read();
	
	for(i=2;i<=n;i++){
		fa[i] = read();
		e[fa[i]].push_back(i);
	}
	
	dfs(1);
	
	for(i=1;i<=n;i++){
		while(sum < i){
			j++;
			sum += w[j];
		}
		
		printf("%d ", j);
	}
	printf("\n");
	
	return 0;
}