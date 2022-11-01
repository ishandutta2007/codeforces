#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	printf("%d\n", 3 * n + 4);
	printf("0 0\n");
	printf("0 1\n");
	printf("1 0\n");
	printf("1 1\n");
	for(i=1;i<=n;i++){
		printf("%d %d\n", i + 1, i);
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", i + 1, i + 1);
	}
	
	return 0;
}