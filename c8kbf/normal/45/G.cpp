#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 6E3+8;

_ n, s, o[maxn];

void op();
bool ip(_ x);
int main() {
	
	scanf("%lld", &n);
	s = (n*(n+1))>>1;
	for(_ i = 1; i <= n; ++i) o[i] = 1;
	if(ip(s)) op();
	for(_ i = 1; i <= n; ++i) if(ip(i) && ip(s-i)) {
		o[i] = 2;
		op();
	}
	s -= 3;
	o[1] = o[2] = 3;
	for(_ i = 3; i <= n; ++i) if(ip(i) && ip(s-i)) {
		o[i] = 2;
		op();
	}	
	
	return 0;
}

bool ip(_ x) {
	if(x == 1) return false;
	for(_ i = 2; i*i <= x; ++i) if(!(x%i)) return false;
	return true;
}

void op() {
	for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
	putchar(10);
	exit(0);
}