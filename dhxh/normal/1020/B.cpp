#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int n, m;

int p[maxn];

int v[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x){
	v[x]++;
	if(v[x] > 1){
		return x;
	}else{
		return dfs(p[x]);
	}
	
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		p[i] = read();
	}
	
	for(i=1;i<=n;i++){
		memset(v, 0, sizeof(v));
		printf("%d ", dfs(i));
	}
	
	printf("\n");
	
	return 0;
}