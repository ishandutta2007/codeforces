#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
unsigned n, A, B, C, D, limit;
unsigned f[MAXN], tot, prime[MAXN], sum1[MAXN], sum2[MAXN], sum3[MAXN];
unsigned m, x[MAXN], id1[MAXN], id2[MAXN], ans0[MAXN], ans1[MAXN], ans2[MAXN], ans3[MAXN];
void init(unsigned n) {
	for (unsigned i = 2; i <= n; i++) {
		if (f[i] == 0) {
			f[i] = i;
			prime[++tot] = i;
			sum1[tot] = sum1[tot - 1] + i;
			sum2[tot] = sum2[tot - 1] + i * i;
			sum3[tot] = sum3[tot - 1] + i * i * i;
		}
		for (unsigned j = 1; j <= tot && prime[j] <= f[i]; j++){
			unsigned tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
unsigned get2(unsigned x) {
	unsigned a = x;
	unsigned b = x + 1;
	unsigned c = 2 * x + 1;
	if (a % 2 == 0) a /= 2;
	else if (b % 2 == 0) b /= 2;
	else c /= 2;
	if (a % 3 == 0) a /= 3;
	else if (b % 3 == 0) b /= 3;
	else c /= 3;
	return a * b * c;
}
unsigned get3(unsigned x) {
	unsigned a = x;
	unsigned b = x + 1;
	if (a % 2 == 0) a /= 2;
	else b /= 2;
	return a * b * a * b;
}
int main(){
	read(n), read(A), read(B), read(C), read(D);
	limit = sqrt(n); init(limit);
	for (unsigned i = 1, j; i <= n; i = j + 1){
		j = n / (n / i); x[++m] = n / i;
		if (x[m] <= limit) id1[x[m]] = m;
		else id2[n / x[m]] = m;
		ans0[m] = x[m] - 1;
		if ((x[m] + 2) % 2 == 0) ans1[m] = ((x[m] + 2) / 2) * (x[m] - 1);
		else ans1[m] = (x[m] + 2) * ((x[m] - 1) / 2);
		ans2[m] = get2(x[m]) - 1;
		ans3[m] = get3(x[m]) - 1;
	}
	for (unsigned j = 1; j <= tot; j++)
		for (unsigned i = 1; i <= m && prime[j] * prime[j] <= x[i]; i++) {
			unsigned k = (x[i] / prime[j] <= limit) ? id1[x[i] / prime[j]] : id2[n / (x[i] / prime[j])];
			ans3[i] = ans3[i] - prime[j] * prime[j] * prime[j] * (ans3[k] - sum3[j - 1]);
			ans2[i] = ans2[i] - prime[j] * prime[j] * (ans2[k] - sum2[j - 1]);
			ans1[i] = ans1[i] - prime[j] * (ans1[k] - sum1[j - 1]);
			ans0[i] = ans0[i] - ans0[k] + j - 1;
		}
	unsigned ans = 0;
	for (int i = 1; i <= tot; i++) {
		unsigned cnt = 0;
		unsigned tmp = n;
		while (tmp >= prime[i]) {
			cnt += tmp / prime[i];
			tmp /= prime[i];
		}
		ans += cnt * (A * prime[i] * prime[i] * prime[i] + B * prime[i] * prime[i] + C * prime[i] + D);
	}
	for (unsigned i = 1; x[i] > limit; i++) {
		ans += i * (ans3[i] - ans3[i + 1]) * A;
		ans += i * (ans2[i] - ans2[i + 1]) * B;
		ans += i * (ans1[i] - ans1[i + 1]) * C;
		ans += i * (ans0[i] - ans0[i + 1]) * D;
	}
	writeln(ans);
	return 0;
}