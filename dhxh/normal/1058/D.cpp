#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k;

long long gcd(long long x, long long y){
	if(x % y == 0){
		return y;
	}else{
		return gcd(y, x % y);
	}
}

int main(){
	int i, j;
	long long tmp;
	long long x, y;
	cin >> n >> m >> k;
	
	if(n * m * 2 / k * k != n * m * 2){
		cout << "NO" << endl;
		return 0;
	}
	
	tmp = 2 * n * m / k;
	if(gcd(n, tmp) != 1){
		x = gcd(n, tmp);
		y = tmp / x;
	}else{
		y = gcd(m, tmp);
		x = tmp / y;
	}
	
	if(x > n){
		y *= x / n;
		x = n;
	}
	if(y > m){
		x *= y / m;
		y = m;
	}
	
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << x << " 0" << endl;
	
	cout << "0 " << y << endl;
	
	return 0;
}