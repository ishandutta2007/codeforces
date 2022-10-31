#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

long long gcd(long long x, long long y){
	if(x % y){
		return gcd(y, x % y);
	}else{
		return y;
	}
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long a, b, x, y;
	
	cin >> a >> b >> x >> y;
	
	long long g = gcd(x, y);
	x /= g;
	y /= g;
	
	cout << min(a / x, b / y) << endl;
	
	return 0;
}