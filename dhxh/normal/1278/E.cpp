#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

vector <int> e[maxn]; 
int w[maxn];
int son[maxn];
pair <int, int> a[maxn];
int n;

int dfs(int x, int fa){
	w[x] = 1;
	for(int y : e[x]){
		if(y == fa) continue;
		son[x]++;
		dfs(y, x);
		w[x] += w[y];
	}
	
	return 0;
}

int dfsb(int x, int fa){
	int cnt = 0;
	int r = a[x].second;
	for(int y : e[x]){
		if(y == fa) continue;
		cnt++;
		a[y].first = a[x].second - cnt;
		a[y].second = r + son[y] + 1;
		r += w[y] * 2 - 1;
		dfsb(y, x);
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dfs(1, -1);
	
	a[1].first = 1;
	a[1].second = 1 + son[1] + 1;
	
	dfsb(1, -1);
	
	for(i=1;i<=n;i++){
		printf("%d %d\n", a[i].first, a[i].second);
	}
	
	return 0;
}
/*
4
1 4
2 5
3 6
7 8
*/