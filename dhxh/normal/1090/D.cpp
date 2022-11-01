#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];

map <pair <int, int>, bool> s;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		s[make_pair(min(x, y), max(x, y))] = true;
	}
	
	if(m == 1ll * n * (n - 1) / 2){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	
	x = y = 0;
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(!s[make_pair(i, j)]){
				x = i;
				y = j;
				break;
			}
		}
		if(x){
			break;
		}
	}
	
	int cnt = 2;
	
	for(i=1;i<=n;i++){
		if(i != x and i != y){
			a[i] = ++cnt;
		}else if(i == x){
			a[i] = 1;
		}else{
			a[i] = 2;
		}
		
	}
	
	for(i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	for(i=1;i<=n;i++){
		if(i == y){
			printf("%d ", a[x]);
		}else{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	
	return 0;
}