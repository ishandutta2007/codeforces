#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a[1005];
int b[1005];

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
			b[i] = read();
		}
		
		int l = 1, r = 0;
		
		for(i=1;i<=7000;i++){
			while(r < n and a[r + 1] <= i){
				r++;
			}
			
			while(l <= r and b[l] < i){
				printf("0 ");
				l++;
			}
			
			if(r >= l){
				printf("%d ", i);
				l++;
			}
		}
		printf("\n");
	}
	
	return 0;
}