#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e6 + 5;
const int MAXV = 6e6 + 5;
const int Maxans = 12;
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
int n, q, a[MAXN], ans[MAXQ];
int r[Maxans + 5], Max[MAXV][Maxans + 5];
int tot, prime[MAXV], f[MAXV], cnt[MAXV];
vector <int> pos[MAXN], home[MAXN];
void init() {
	for (int i = 2; i < MAXV; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i, cnt[i] = 1;
		for (unsigned j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp >= MAXV) break;
			f[tmp] = prime[j];
			cnt[tmp] = cnt[i] + 1;
		}
	}
}
int process(int x) {
	int ans = 1;
	for (int i = 1; prime[i] * prime[i] <= x; i++)
		if (x % prime[i] == 0) {
			int cnt = 0;
			while (x % prime[i] == 0) x /= prime[i], cnt++;
			if (cnt & 1) ans *= prime[i];
		}
	return ans * x;
}
int main() {
	read(n), read(q);
	init();
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		a[i] = process(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		pos[y].push_back(x);
		home[y].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				int now = cnt[a[i] / j];
				for (int k = 0; k + now <= Maxans; k++)
					chkmax(r[k + now], Max[j][k]);
				now = cnt[j];
				for (int k = 0; k + now <= Maxans; k++)
					chkmax(r[k + now], Max[a[i] / j][k]);
			}
		}
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				chkmax(Max[j][cnt[a[i] / j]], i);
				chkmax(Max[a[i] / j][cnt[j]], i);
			}
		}
		for (unsigned j = 0; j < pos[i].size(); j++) {
			int tans = Maxans;
			for (int k = 0; k <= Maxans; k++)
				if (r[k] >= pos[i][j]) chkmin(tans, k);
			ans[home[i][j]] = tans;
		}
	}
	for (int i = 1; i <= q; i++)
		writeln(ans[i]);
	return 0;
}