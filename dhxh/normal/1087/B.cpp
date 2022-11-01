#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t, k;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	long long ans = 1e18;
	
	cin >> n >> k;
	
	for(i=1;i<=sqrt(n);i++){
		if(n % i == 0){
			if(n / i < k){
				ans = min(ans, i * k + n / i);
			}
			if(i < k){
				ans = min(ans, n / i * k + i);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}