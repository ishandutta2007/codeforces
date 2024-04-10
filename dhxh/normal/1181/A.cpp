#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x, y;
	
	cin >> n >> m >> t;
	
	x = (n / t + m / t);
	y = (n + m) / t;
	
	if(x == y){
		cout << x << " " << 0 << endl;
	}else{
		cout << y << " " << min((y - x) * t - n % t, (y - x) * t - m % t) << endl;
	}
	
	return 0;
}