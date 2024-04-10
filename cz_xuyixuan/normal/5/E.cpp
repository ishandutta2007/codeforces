#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int a[MAXN], rk[MAXN];
int f[MAXN], size[MAXN], cnt[MAXN];
bool flg[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void merge(int x, int y) {
	if (flg[y] == false) return;
	x = F(x), y = F(y);
	if (x == y) return;
	f[x] = y; size[y] += size[x];
}
bool cmp(int x, int y) {
	return a[x] < a[y];
}
int main() {
	int T; T = 1;
	while (T--) {
		int n; read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
			f[i] = i, rk[i] = i, size[i] = 1;
		sort(rk + 1, rk + n + 1, cmp);
		memset(flg, false, sizeof(flg));
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[rk[i]] == a[rk[i + 1]]) continue;
			for (int j = i; a[rk[i]] == a[rk[j]]; j--) {
				flg[rk[j]] = true;
				if (rk[j] == 1) merge(rk[j], n);
				else merge(rk[j], rk[j] - 1);
				if (rk[j] == n) merge(rk[j], 1);
				else merge(rk[j], rk[j] + 1);
			}
			for (int j = i; a[rk[i]] == a[rk[j]]; j--) {
				ans += min(2, n - size[F(rk[j])]);
				ans += cnt[F(rk[j])];
				cnt[F(rk[j])]++;
			}
			for (int j = i; a[rk[i]] == a[rk[j]]; j--)
				cnt[F(rk[j])]--;
		}
		cout << ans << endl;
	}
	return 0;
}