#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;
long long k, a, b;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long ans = 0;
	
	cin >> n >> k >> a >> b;
	
	while(n > 1){
		if(n < k){
			ans += (n - 1) * a;
			n = 1;
		}else if(n % k){
			ans += a * (n % k);
			n -= n % k;
		}else{
			t = n - n / k;
			if(t * a <= b){
				ans += (n - 1) * a;
				n = 1;
			}else{
				ans += b;
				n /= k;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}