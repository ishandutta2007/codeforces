#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a[105];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int maxn = 0;
	
	n = read();
	
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		maxn = max(maxn, a[i]);
	}
	
	for(i=1;i<=n;i++){
		t += maxn - a[i];
	}
	
	if(t >= m){
		printf("%d %d\n", maxn, maxn + m);
	}else{
		if((m - t) % n){
			printf("%d %d\n", maxn + (m - t) / n + 1, maxn + m);
		}else{
			printf("%d %d\n", maxn + (m - t) / n, maxn + m);
		}
	}
	
	return 0;
}