#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

const int maxn = 150005;

int fa[maxn];
long long son[maxn];
long long num[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int init(){
	int i, j;
	
	for(i=1;i<=n;i++){
		fa[i] = i;
		son[i] = 1;
		num[i] = 0;
	}
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	
	if(ra != rb){
		fa[rb] = ra;
		son[ra] += son[rb];
		num[ra] += 1 + num[rb];
	}else{
		num[ra]++;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	int r;
	
	n = read();
	m = read();
	
	init();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		join(x, y);
	}
	
	for(i=1;i<=n;i++){
		r = find(i);
		if(son[r] * (son[r] - 1) / 2 != num[r]){
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	return 0;
}