#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

char ans[105];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=min(n, m);i++){
		ans[i] = 'a' + i - 1;
	}
	
	for(i=m+1;i<=n;i++){
		if(ans[i - 1] == 'a'){
			ans[i] = 'b';
		}else{
			ans[i] = 'a';
		}
	}
	
	for(i=1;i<=n;i++){
		printf("%c", ans[i]);
	}
	
	printf("\n");
	
	return 0;
}