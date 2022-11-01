#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

long long mabs(long long x){
	return x < 0 ? -x : x;
}

long long gcd(long long x, long long y){
	if(x % y){
		return gcd(y, x % y);
	}else{
		return y;
	}
}

long long ex_gcd(long long a, long long b, long long &x, long long &y){
	if(a == 0){
		x = 0, y = 1;
		return b;
	}
	long long x1, y1;
	long long d = ex_gcd(b % a, a, x1, y1);
	
	x = y1 - (b / a) * x1;
	y = x1;
	
	return d;
}

int main(){
	long long i, j;
	long long x = 0, y = 0;
	long long a, b;
	bool flag = false;
	
	cin >> n;
	
	for(i=2;i<=sqrt(n);i++){
		if(n % i == 0){
			if(x){
				if(gcd(x, i) == 1){
					y = i;
					flag = true;
					break;
				}
				if(gcd(x, n / i) == 1){
					y = n / i;
					flag = true;
					break;
				}
			}else{
				x = i;
				if(gcd(x, n / i) == 1){
					y = n / i;
					flag = true;
					break;
				}
			}
		}
	}
	
	if(!flag){
		cout << "NO" << endl;
		return 0;
	}
	
	long long g = ex_gcd(x, y, a, b);
	
	if((n - 1) % g){
		cout << "NO" << endl;
		return 0;
	}
	
	a *= (n - 1) / g;
	b *= (n - 1) / g;
	
	if(a < 0){
		int tmp = (mabs(a) / y);
		a += tmp * y;
		b -= tmp * x;
		if(a < 0){
			a += y;
			b -= x;
		}
	}
	
	if(b < 0){
		int tmp = (mabs(b) / x);
		b += tmp * x;
		a -= tmp * y;
		if(b < 0){
			b += x;
			a -= y;
		}
	}
	
	cout << "YES" << endl;
	cout << 2 << endl;
	cout << a << " " << n / x << endl;
	cout << b << " " << n / y << endl;
	
	return 0;
}