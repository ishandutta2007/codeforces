#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i=0; i<a; i++)
#define ll long long

int main() {
	int k, MOD = 1000000007; 
	ll cur = 1,a,p=2,z=1;
	bool e = 0;
	cin >> k;
	F0R(i,k) {
		cin >> a;
		if (!(a%2)) e = 1;
		a %= (MOD-1);
		cur = cur*a % (MOD-1);
	}
	cur --;
	if (cur<0) cur += (MOD-1);
	while (cur) {
		if (cur & 1) z = z*p % MOD;
		p = p*p % MOD;
		cur /= 2;
	}
	ll z1 = z;
	while (z1 % 3 != (e+1)) z1 += MOD;
	cout << (z1+1)/3 << "/" << z;
}