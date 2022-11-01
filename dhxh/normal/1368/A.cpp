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
	long long a, b, n;
	
	t = read();
	
	while(t--){
		a = read();
		b = read();
		n = read();
		
		if(a > b){
			swap(a, b);
		}
		
		int cnt = 0;
		
		while(b <= n){
			a += b;
			swap(a, b);
			cnt++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}