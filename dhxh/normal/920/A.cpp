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
	int x, y;
	
	t = read();
	
	while(t--){
		n = read();
		m = read();
		int ans = 0;
		
		x = read();
		y = x;
		
		ans = x;
		
		for(i=2;i<=m;i++){
			y = read();
			ans = max(ans, (y - x + 1) / 2 + (y - x + 1) % 2);
			x = y;
		}
		
		ans = max(ans, n - y + 1);
		printf("%d\n", ans);
	}
	
	return 0;
}