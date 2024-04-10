#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define Mod 1000000007LL
long long pow(long long x) {
	if(x==0) return 1;
	if(x==1) return 2;
	long long tmp = pow(x/2);
	tmp = tmp * tmp % Mod;
	if(x & 1) return tmp * 2 % Mod;
	else return tmp;
}

long long pow_mod(long long x, int n) {
	if(n==0) return 1;
	if(n==1) return x;
	long long tmp = pow_mod(x, n/2);
	tmp = tmp * tmp % Mod;
	if(n & 1) return tmp*x%Mod;
	else return tmp;
}

void gcd(long long a, long long b, long long & d, long long & x, long long & y) {
	if(!b){d = a; x = 1; y = 0;}
	else {gcd(b, a%b, d, y, x); y -= x*(a/b);};
}

long long inv(long long a, long long n) {
	long long d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x+n)%n : -1;
}

int main() {
	char s[100010];
	int b;
	scanf("%s%d", s, &b);

	int sz = strlen(s);
	long long ans = 0, r = pow(sz), ir;
	ir = inv(r-1, Mod);

	for(int i = sz-1; i >= 0; --i)
		if((s[i]-'0')%5==0) {
			long long a1 = pow(i);
			ans += a1;
			ans %= Mod;
		}
	ans = ans * (pow_mod(r, b) - 1) % Mod * ir % Mod;
	cout << ans << endl;
	return 0;
}