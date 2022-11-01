#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a[1005], b[1005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		for(i=1;i<=n;i++){
			a[i] = read();
		}
		for(i=1;i<=n;i++){
			b[i] = read();
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for(i=1;i<=n;i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		for(i=1;i<=n;i++){
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	
	return 0;
}