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

int l[maxn];
int ans[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long sum = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		l[i] = read();
		sum += l[i];
	}
	
	if(sum < n){
		printf("-1\n");
		return 0;
	}
	
	for(i=1,j=1;i<=m;i++,j++){
		sum -= l[i];
		while(n - (j + l[i] - 1) > sum) j++;
		int x = j;
		if(x + l[i] - 1 > n){
			printf("-1\n");
			return 0;
		}
		ans[i] = x;
	}
	
	for(i=1;i<=m;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}