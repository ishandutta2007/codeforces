#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 1e6+50;
int q; LL n, m, gg,a,b,c,d;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
int main(){
	cin >> n >> m >> q;
	gg = gcd(n, m);
	n /= gg; m /= gg;
	for (int i = 1; i <= q; i++) {
		cin >> a >> b >> c >> d;
		if (a == 1)b = (b - 1) / n;
		if (a == 2)b = (b - 1) / m;
		if (c == 1)d = (d - 1) / n;
		if (c == 2)d = (d - 1) / m;
		puts(b == d ? "YES" : "NO");
	}
	return 0;
}