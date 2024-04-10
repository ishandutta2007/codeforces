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

int n, m, q, t;

int a[maxn];
int b[maxn];

int fa[maxn][20];

int f[maxn];
int ans[maxn];
int last[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int l, r;
	
	n = read();
	m = read();
	q = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		last[a[i]] = a[i - 1];
	}
	last[a[1]] = a[n];
	
	for(i=1;i<=m;i++){
		b[i] = read();
	}
	
	for(i=1;i<=m;i++){
		fa[i][0] = f[last[b[i]]];
		f[b[i]] = i;
	}
	
	for(i=1;i<=m;i++){
		for(j=0;fa[fa[i][j]][j];j++){
			fa[i][j + 1] = fa[fa[i][j]][j];
		}
	}
	
	for(i=1;i<=m;i++){
		ans[i] = i;
		int x = n - 1;
		for(j=20;j>=0;j--){
			if(x >= (1 << j)){
				ans[i] = fa[ans[i]][j];
				x -= (1 << j);
			}
		}
		ans[i] = max(ans[i], ans[i - 1]);
	}
	
	while(q--){
		l = read();
		r = read();
		
		if(ans[r] >= l){
			printf("1");
		}else{
			printf("0");
		}
	}
	
	printf("\n");
	
	return 0;
}