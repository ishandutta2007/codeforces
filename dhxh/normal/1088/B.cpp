#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t, k;

int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int d = 0;
	
	n = read();
	k = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	for(i=1,j=1;i<=k;i++){
		while(a[j] <= d and j<= n){
			j++;
		}
		if(i > n or j > n){
			printf("0\n");
			continue;
		}
		printf("%d\n", a[j] - d);
		d = a[j];
	}
	
	return 0;
}