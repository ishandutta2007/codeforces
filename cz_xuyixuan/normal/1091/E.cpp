#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
int n, a[MAXN], ans[MAXN];
ll s[MAXN], p[MAXN], q[MAXN], v[MAXN];
int main() {
	read(n);
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int pos = n, qos = n;
	ll pre = 0;
	for (int i = 1; i <= n; i++) {
		pre += a[i];
		while (pos >= 1 && a[pos] <= i) pos--;
		while (qos >= 1 && a[qos] <= i + 1) qos--;
		if (pos >= i) p[i] = i * (i - 1ll) + 1ll * (pos - i) * i + s[n] - s[pos];
		else p[i] = i * (i - 1ll) + s[n] - s[i];
		if (qos >= i) q[i] = i * (i + 1ll) + 1ll * (qos - i) * (i + 1) + s[n] - s[qos];
		else q[i] = i * (i + 1ll) + s[n] - s[i];
		p[i] = pre - p[i];
		if (p[i] <= 0) p[i] = 0;
		else if (p[i] > i) p[i] = 1e18;
		v[i] = q[i];
		q[i] -= pre;
	}
	a[0] = n, a[n + 1] = -1, q[n + 1] = 1e18;
	for (int i = 1; i <= n; i++)
		if (a[i]) v[0]++;
	for (int i = 1; i <= n; i++)
		chkmax(p[i], p[i - 1]);
	for (int i = n; i >= 1; i--)
		chkmin(q[i], q[i + 1]);
	vector <int> ans;
	for (int i = 0; i <= n; i++) {
		if (i == 0) pre = 0;
		else pre += a[i];
		for (int j = a[i]; j > a[i + 1]; j--)
			if ((j + sum) % 2 == 0 && j >= p[i] && j <= q[i + 1] && pre + j <= v[i]) ans.push_back(j);
	}
	if (ans.empty()) puts("-1");
	else {
		sort(ans.begin(), ans.end());
		for (auto x : ans)
			printf("%d ", x);
	}
	return 0;
}