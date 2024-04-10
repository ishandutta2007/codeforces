#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int n; ll a[MAXN];
int calc(ll g) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < g) ans += g - a[i];
		else {
			ll tmp = a[i] % g;
			ans += min(tmp, g - tmp);
		}
	}
	if (ans > n) return n;
	else return ans;
}
int work(ll tmp) {
	int ans = n;
	if (tmp == 0) return n;
	for (int i = 2; 1ll * i * i <= tmp; i++)
		while (tmp % i == 0) {
			tmp /= i;
			chkmin(ans, calc(i));
		}
	if (tmp != 1) chkmin(ans, calc(tmp));
	return ans;
}
int main() {
	read(n);
	srand('X' + 'Y' + 'X');
	for (int i = 1; i <= n; i++)
		read(a[i]);
	random_shuffle(a + 1, a + n + 1);
	int ans = n;
	for (int i = 1; i <= 40; i++) {
		int pos = ((rand() << 15) + rand()) % n + 1;
		chkmin(ans, work(a[pos]));
		chkmin(ans, work(a[pos] + 1));
		chkmin(ans, work(a[pos] - 1));
	}
	cout << ans << endl;
	return 0;
}