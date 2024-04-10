#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long a, b, p, n;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long ex_gcd(long long aa, long long bb, long long &x, long long &y){
	if(aa == 0){
		x = 0;
		y = 1;
		return bb;
	}
	
	long long x1, y1;
	
	long long d = ex_gcd(bb % aa, aa, x1, y1);
	x = y1 - (bb / aa) * x1;
	y = x1;
	
	return d;
}

int main(){
	long long i, j;
	long long t = 1;
	long long x, y;
	long long l, g;
	long long ans = 0;
	long long c;
	long long k;
	
	cin >> a >> b >> p >> n;
	
	for(i=1;i<p;i++){
		t = t * a % p;
		g = ex_gcd(t, p, x, y);
		x *= b / g;
		y *= b / g;
		l = t * p / g;
		c = l / t;
		x %= c;
		while(x <= 0){
			x += c;
		}
		
		k = x;
		
		g = ex_gcd(p - 1, c, x, y);
		x *= (k - i) / g;
		y *= (k - i) / g;
		l = (p - 1) * c / g;
		c = l / (p - 1);
		x %= c;
		while(x < 0){
			x += c;
		}
		
		y = i + (p - 1) * x;
		if(y <= n){
			ans++;
			ans += (n - y) / ((p - 1) * c);
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}