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
	int x;
	int a, b;
	bool flag;
	
	t = read();
	
	while(t--){
		x = read();
		if(x == 0){
			printf("1 1\n");
			continue;
		}
		flag = false;
		for(i=1;i<sqrt(x);i++){
			if(x % i == 0 and (i + x / i) % 2 == 0){
				a = (i + x / i) / 2;
				b = x / i - a;
				for(j=max(1, a / b - 1);j<=max(1, a / b + 2);j++){
					if(a / j == b){
						b = j;
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
		}
		
		if(flag){
			printf("%d %d\n", a, b);
		}else{
			printf("-1\n");
		}
	}
	
	return 0;
}