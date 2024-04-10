#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m;

long long x, d;

long long ans = 0;

int main(){
	int i, j;
	
	cin >> n >> m;
	
	while(m--){
		cin >> x >> d;
		if(n & 1){
			ans += x * n;
			if(d > 0){
				ans += (n - 1) * n / 2 * d;
			}else{
				ans += (n / 2) * (n / 2 + 1) * d;
			}
		}else{
			ans += x * n;
			if(d > 0){
				ans += (n - 1) * n / 2 * d;
			}else{
				ans += (((n / 2) * (n / 2 - 1) / 2) + ((n / 2) * (n / 2 + 1) / 2)) * d;
			}
		}
	}
	
	printf("%.12f\n", (double)ans / (double)n);
	
	return 0;
}