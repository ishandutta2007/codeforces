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
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
ll n, k, a, b, Max, Min;
void work(ll x) {
	for (int i = 1; i <= n; i++) {
		chkmax(Max, gcd(x, n * k));
		chkmin(Min, gcd(x, n * k));
		x += k;
	}
}
int main() {
	read(n), read(k);
	read(a), read(b);
	if (a < b) swap(a, b);
	Max = 1, Min = n * k;
	work(a - b), work(k - a - b);
	write(n * k / Max), putchar(' '), writeln(n * k / Min);
	return 0;
}