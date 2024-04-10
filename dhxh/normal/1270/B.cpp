#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
int b[maxn];
int c[maxn];

bool cmp(int x, int y){
	return b[x] < b[y];
}

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
		
		int minx = a[1] - 1, x = 1, y;
		bool flag = false;
		
		for(i=2;i<=n;i++){
			if(a[i] - i > minx){
				y = i;
				flag = true;
				break;
			}
			if(a[i] - i < minx){
				minx = a[i] - i;
				x = i;
			}
		}
		
		if(flag){
			printf("YES\n%d %d\n", x, y);
			continue;
		}
		
		minx = a[n] + n, x, y = n;
		
		for(i=n-1;i>0;i--){
			if(a[i] + i > minx){
				x = i;
				flag = true;
				break;
			}
			if(a[i] + i < minx){
				minx = a[i] + i;
				y = i;
			}
		}
		if(flag){
			printf("YES\n%d %d\n", x, y);
			continue;
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}