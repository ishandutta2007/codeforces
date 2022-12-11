#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(int x) { x %= mod; return x + (x >> 31 & mod); }
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
struct num {
	int v;
	num() { v = 0; }
	num(int x) { v = remod(x); }
	num(LL x) { v = remod(x); }
	friend num operator + (num a, num b) {
		reduce(a.v += b.v - mod);
		return a;
	}
	friend num operator - (num a, num b) {
		reduce(a.v -= b.v);
		return a;
	}
	friend num operator * (num a, num b) {
		return num(mul(a.v, b.v));
	}
} ;
num pow(num x, int b) { return num(pow(x.v, b)); }
num calc(num a, num b, num x, num m) {
	return pow(420,mod-2)*(70*pow(a,6)-20*pow(a,7)+14*pow(a,5)*(1+3*m-6*pow(x,2))-105*pow(a,4)*(2+m-2*pow(x,2))-35*pow(a,2)*(-4-3*m+6*(2+m)*pow(x,2)-6*pow(x,4))+70*pow(a,3)*(1+2*(1+m)*pow(x,2)-2*pow(x,4))-2*a*(32+7*m*(13+5*m*(3+m))+63*pow(x,2)+70*m*pow(x,2)-35*(5+3*m)*pow(x,4)+70*pow(x,6))+(1+b)*(50*pow(b,5)+20*pow(b,6)+70*(1+m-pow(x,2))*(2+m-pow(x,2))*(m+2*pow(x,2))+pow(b,4)*(-64-42*m+84*pow(x,2))+pow(b,3)*(-146-63*m+126*pow(x,2))+2*b*(32+21*m-7*(11+5*m)*pow(x,2)+35*pow(x,4))+pow(b,2)*(76+63*m-14*(19+10*m)*pow(x,2)+140*pow(x,4))));
}
LL n;
num calc(LL x) {
	LL lim = std::sqrt(n - x * x);
	if ((lim + 1) * (lim + 1) + x * x <= n) ++lim;
	return calc(-lim, lim, x, n) * (x ? 2 : 1);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; num ans;
	for (LL i = 0; i * i <= n; ++i) ans = ans + calc(i);
	std::cout << ans.v << std::endl;
	return 0;
}