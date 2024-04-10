#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXV = 2e6 + 5;
const int P = 1e9 + 7;
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
int n, tot, prime[MAXV], f[MAXV];
int a[MAXN], Max[MAXV], cnt[MAXV];
bool type[MAXN];
void init(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	init(2e6);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (Max[a[i]]) {
			type[i] = true;
			int tmp = a[i] - 1;
			while (tmp != 1) {
				int fac = f[tmp], now = 0;
				while (tmp % fac == 0) {
					tmp /= fac;
					now++;
				}
				if (now > Max[fac]) {
					Max[fac] = now;
					cnt[fac] = 1;
				} else cnt[fac] += Max[fac] == now;
			}
		} else Max[a[i]] = cnt[a[i]] = 1;
	}
	int ans = 1;
	for (int i = 1; i <= 2e6; i++)
	for (int j = 1; j <= Max[i]; j++)
		ans = 1ll * ans * i % P;
	for (int i = 1; i <= n; i++) {
		bool found = false;
		if (type[i]) {
			found = true;
			int tmp = a[i] - 1;
			while (tmp != 1) {
				int fac = f[tmp], now = 0;
				while (tmp % fac == 0) {
					tmp /= fac;
					now++;
				}
				found &= Max[fac] > now || cnt[fac] >= 2;
			}
		} else found = Max[a[i]] >= 2 || cnt[a[i]] >= 2;
		if (found) {
			writeln((ans + 1) % P);
			return 0;
		}
	}
	writeln(ans);
	return 0;
}