#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n; vector <int> a[MAXN];
int tot, prime[MAXN], f[MAXN];
void sieve(int n) {
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
	read(n), sieve(2e5);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		while (x != 1) {
			int y = f[x], cnt = 0;
			while (x % y == 0) {
				x /= y;
				cnt++;
			}
			a[y].push_back(cnt);
		}
	}
	ll ans = 1;
	for (int i = 1; i <= 2e5; i++)
		if (a[i].size() >= n - 1) {
			sort(a[i].begin(), a[i].end(), [&] (int x, int y) {
				return x > y;
			});
			int tmp = a[i][n - 2];
			while (tmp--) ans *= i;
		}
	cout << ans << endl;
	return 0;
}