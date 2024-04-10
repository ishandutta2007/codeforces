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

long long a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x = -1, y;
	long long sum = 0;
	int cnt = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	if(a[1] == a[2] and a[1] == 0){
		printf("cslnb\n");
		return 0;
	}
	
	for(i=2;i<=n;i++){
		if(a[i] == a[i - 1]){
			if(a[i - 2] + 1 == a[i] and i != 2){
				printf("cslnb\n");
				return 0;
			}
			cnt++;
		}
	}
	
	if(cnt >= 2){
		printf("cslnb\n");
		return 0;
	}
	
	for(i=1;i<=n;i++){
		if(a[i] > x){
			x++;
			sum += a[i] - x;
		}
	}
	
	if(sum % 2 == 0){
		printf("cslnb\n");
	}else{
		printf("sjfnb\n");
	}
	
	return 0;
}