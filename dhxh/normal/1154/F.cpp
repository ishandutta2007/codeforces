#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, k, t;

int a[maxn];

int p[maxn];

int f[2005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int sum(int l, int r){
	return a[r] - a[l + p[r - l + 1] - 1];
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	k = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		p[x] = max(p[x], y);
	}
	
	sort(a + 1, a + n + 1);
	
	for(i=1;i<=n;i++){
		a[i] += a[i - 1];
	}
	
	memset(f, 0x3f, sizeof(f));
	
	f[0] = 0;
	
	for(i=1;i<=k;i++){
		for(j=0;j<i;j++){
			f[i] = min(f[i], f[j] + sum(j + 1, i));
		}
	}
	
	printf("%d\n", f[k]);
	
	return 0;
}