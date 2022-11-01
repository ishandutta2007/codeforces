#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e6 + 5;

int n;

int a[maxn];
int f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int lowbit(int x){
	return x & -x;
}

int insert(int x, int y){
	if(f[x | y] > 1)return 0;
	f[x | y]++;
	
	for(int nx=x,ny=0;nx;nx^=lowbit(nx)){
		insert(nx ^ lowbit(nx), ny | y);
		ny |= lowbit(nx);
	}
	
	return 0;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=0;i<n;i++){
		a[n - i] = read();
	}
	
	int ans = 0;
	
	for(i=1;i<=n;i++){
		int ret = 0;
		for(j=20;j>=0;j--){
			if((a[i] >> j) & 1)continue;
			if(f[ret | (1 << j)] > 1)ret |= (1 << j);
		}
		if(i > 2)ans = max(ans, a[i] | ret);
		insert(a[i], 0);
	}
	
	printf("%d\n", ans);
	
	return 0;
}