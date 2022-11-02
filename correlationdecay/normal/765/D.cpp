#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#define maxn 1000009
using namespace std;
int n;
int f[maxn],g[maxn],h[maxn];
bool check(){
	for(int i = 1; i <= n; i++){
		if(f[f[i]] != f[i])
			return 0;
	}
	return 1;
}
int vis[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n; i++){
		scanf("%d", &f[i]);
	}	
	if(!check()){
		puts("-1");
		return 0;
	}
	memset(vis, -1, sizeof(vis));
	int m = 0;
	for(int i = 1; i <= n; i++){
		if(vis[f[i]] == -1){
			m++;
			vis[f[i]] = m;
			h[m] = f[i];
		}
		g[i] = vis[f[i]];
	}
	printf("%d\n", m);
	for(int i = 1; i<=n ;i++){
		printf("%d", g[i]);
		if(i == n)
			puts("");
		else
			printf(" ");
	}
	for(int i = 1;i <= m; i++){
		printf("%d", h[i]);
		if(i == m)
			puts("");
		else
			printf(" ");
	}
	return 0;
}