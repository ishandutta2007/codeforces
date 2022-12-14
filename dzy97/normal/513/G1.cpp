#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[105], rev[105];
long double ans = 0, cnt = 0;

void dfs(int u){
	if(!u){
		for(int i = 1;i <= n;i ++)
			for(int j = i + 1;j <= n;j ++)
				if(a[i] > a[j]) ans ++;
		cnt ++;
		return;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			for(int k = i;k <= (i + j) / 2;k ++) swap(a[k], a[j - (k - i)]);
			dfs(u - 1);
			for(int k = i;k <= (i + j) / 2;k ++) swap(a[k], a[j - (k - i)]);
		}
	}
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	dfs(m);
	printf("%.10lf\n", (double)(ans / cnt));
	return 0;
}