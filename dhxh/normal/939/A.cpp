#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 5;

int n, m, t;

int f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		f[i] = read();
	}
	
	for(i=1;i<=n;i++){
		if(f[f[f[i]]] == i){
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	
	return 0;
}