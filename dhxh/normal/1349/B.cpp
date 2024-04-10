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

int a[maxn];

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
		m = read();
		
		bool flag = false, f = false, g = false;
		int c = 0, d = 0;
		
		for(i=1;i<=n;i++){
			a[i] = read();
			if(a[i] == m) flag = true;
			else if(a[i] > m) c++;
			else d++;
		}
		
		if(!flag){
			printf("no\n");
			continue;
		}
		
		if(!d){
			printf("yes\n");
			continue;
		}
		
		for(i=1;i+2<=n;i++){
			int x = 0;
			if(a[i] >= m) x++;
			if(a[i + 1] >= m) x++;
			if(a[i + 2] >= m) x++;
			if(x >= 2) f = true;
		}
		
		if(f){
			printf("yes\n");
			continue;
		}
		
		printf("no\n");
	}
	
	return 0;
}
/*
3
8 2
1 2 1 2 1 2 1 3
4 2
1 1 2 2
4 2
2 1 1 2
*/