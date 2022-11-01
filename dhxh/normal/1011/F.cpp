#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int n, m;

int fa[maxn];
int son[maxn][2];
int opt[maxn];

char a[15];

int root;

int v[maxn];
int vb[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x){
	int y;
	int ret;
	int tmpa, tmpb;
	
	if(opt[x] == 5){
		v[x] = son[x][0];
	}else if(opt[x] == 4){
		tmpa = dfs(son[x][0]);
		v[x] = !tmpa;
	}else if(opt[x] == 3){
		tmpa = dfs(son[x][0]);
		tmpb = dfs(son[x][1]);
		v[x] = tmpa ^ tmpb;
	}else if(opt[x] == 2){
		tmpa = dfs(son[x][0]);
		tmpb = dfs(son[x][1]);
		v[x] = tmpa | tmpb;
	}else if(opt[x] == 1){
		tmpa = dfs(son[x][0]);
		tmpb = dfs(son[x][1]);
		v[x] = tmpa & tmpb;
	}
	
	return v[x];
}

int dfsb(int x){
	int y, z;
	int ret;
	int tmpa, tmpb;
	
	if(opt[x] == 4){
		vb[son[x][0]] = vb[x];
		dfsb(son[x][0]);
	}else if(opt[x] == 3){
		y = son[x][0];
		z = son[x][1];
		if(((!v[y]) ^ v[z]) == v[x]){
			vb[y] = v[root];
		}else{
			vb[y] = vb[x];
		}
		
		if((v[y] ^ (!v[z])) == v[x]){
			vb[z] = v[root];
		}else{
			vb[z] = vb[x];
		}
		dfsb(son[x][0]);
		dfsb(son[x][1]);
	}else if(opt[x] == 2){
		y = son[x][0];
		z = son[x][1];
		if(((!v[y]) | v[z]) == v[x]){
			vb[y] = v[root];
		}else{
			vb[y] = vb[x];
		}
		
		if((v[y] | (!v[z])) == v[x]){
			vb[z] = v[root];
		}else{
			vb[z] = vb[x];
		}
		dfsb(son[x][0]);
		dfsb(son[x][1]);
	}else if(opt[x] == 1){
		y = son[x][0];
		z = son[x][1];
		if(((!v[y]) & v[z]) == v[x]){
			vb[y] = v[root];
		}else{
			vb[y] = vb[x];
		}
		
		if((v[y] & (!v[z])) == v[x]){
			vb[z] = v[root];
		}else{
			vb[z] = vb[x];
		}
		dfsb(son[x][0]);
		dfsb(son[x][1]);
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		scanf("%s", a);
		if(a[0] == 'A'){
			opt[i] = 1;
			x = read();
			y = read();
			son[i][0] = x;
			son[i][1] = y;
			fa[x] = i;
			fa[y] = i;
		}else if(a[0] == 'O'){
			opt[i] = 2;
			x = read();
			y = read();
			son[i][0] = x;
			son[i][1] = y;
			fa[x] = i;
			fa[y] = i;
		}else if(a[0] == 'X'){
			opt[i] = 3;
			x = read();
			y = read();
			son[i][0] = x;
			son[i][1] = y;
			fa[x] = i;
			fa[y] = i;
		}else if(a[0] == 'N'){
			opt[i] = 4;
			x = read();
			son[i][0] = x;
			fa[x] = i;
		}else if(a[0] == 'I'){
			opt[i] = 5;
			x = read();
			son[i][0] = x;
		}
	}
	
	root = 1;
	
	dfs(root);
	
	vb[root] = !v[root];
	
	dfsb(root);
	
	for(i=1;i<=n;i++){
		if(opt[i] == 5){
			printf("%d", vb[i]);
		}
	}
	
	printf("\n");
	
	return 0;
}