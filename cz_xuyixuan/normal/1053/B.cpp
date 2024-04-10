#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int a[MAXN], s[MAXN][2], sum[MAXN], nxt[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		ll tmp; read(tmp);
		while (tmp) {
			a[i] += tmp & 1;
			tmp >>= 1;
		}
	}
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		s[i][1] = s[i - 1][1];
		s[i][0] = s[i - 1][0];
		if (sum[i] % 2 == 1) s[i][1]++;
		else s[i][0]++;
	}
	int las = n + 1;
	for (int i = n; i >= 0; i--){
		nxt[i] = las;
		if (a[i] != 0) las = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		int tmp = sum[i - 1] % 2;
		int las = i, Max = a[i], sum = a[i];
		for (int j = 1; j <= 128; j++){
			int id = nxt[las]; 
			if (sum / 2 >= Max){
				ans = ans + s[id - 1][tmp] - s[las - 1][tmp];
			}
			Max = max(a[id], Max);
			sum = sum + a[id];
			las = id;
			if (las > n) break;
		}
		ans = ans + s[n][tmp] - s[las - 1][tmp];
	}
	writeln(ans);
	return 0;
}