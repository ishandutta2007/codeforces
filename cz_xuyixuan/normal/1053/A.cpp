#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
ll n, m, k;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	read(n), read(m), read(k);
	ll g = gcd(n, k);
	k = k / g;
	if (m * 2 % k != 0) printf("NO\n");
	else {
		ll x = n / g, y = m * 2 / k;
		if (y > m) x *= 2, y /= 2;
		printf("YES\n");
		printf("0 0\n");
		printf("%I64d %I64d\n", x, 0ll);
		printf("%I64d %I64d\n", 0ll, y);
	}
}