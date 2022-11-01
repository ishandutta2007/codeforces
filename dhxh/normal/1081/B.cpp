#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int a[maxn];
int p[maxn];
int c[maxn];

int cnt = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		a[i] = n - a[i];
		p[i] = i;
	}
	
	sort(p + 1, p + n + 1, cmp);
	
	i = 1;
	
	while(i <= n){
		c[p[i]] = ++cnt;
		for(j=i;j<=i+a[p[i]]-1;j++){
			if(a[p[i]] == a[p[j]]){
				c[p[j]] = cnt;
			}else{
				printf("Impossible\n");
				return 0;
			}
		}
		i += a[p[i]];
	}
	
	printf("Possible\n");
	
	for(i=1;i<=n;i++){
		printf("%d ", c[i]);
	}
	printf("\n");
	
	return 0;
}