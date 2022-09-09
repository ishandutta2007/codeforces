#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
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
int n, t, s, p[MAXN], q[MAXN], a[MAXN];
void update(int pos, int now) {
	if (now != 0) cout << '+' << ' ' << pos << endl;
	int x, y; read(x), read(y);
	p[now] = x - t, t = x;
	q[now] = y - s, s = y;
}
bool check() {
	static int b[MAXN]; int tmp = 0;
	memcpy(b, a, sizeof(a)), b[1] += 2;
	for (int i = 2; i <= n - 1; i++)
		b[i] += 1;
	for (int i = 2; i <= n - 1; i++)
		tmp += b[i - 1] * b[i] * b[i + 1];
	return tmp == s;
}
int main() {
	read(n), update(0, 0);
	for (int i = 1; i <= n - 3; i++)
		update(n - i, i);
	update(1, n - 2);
	update(2, n - 1);
	update(1, n);
	for (int i = 2; true; i++)
		if ((i - 1) * (i - 2) / 2 == p[n]) {
			a[1] = i - 2;
			break;
		}
	a[3] = q[n] - q[n - 2] - 1;
	a[2] = q[n - 2] / (a[3] + 1);
	if (n >= 5) {
		a[4] = q[n - 1] / (a[3] + 1) - a[1] - 2;
		for (int i = 5; i <= n - 1; i++) {
			int pos = i - 2;
			a[i] = (q[n - pos] - a[pos - 1] * a[pos - 2]) / (a[pos + 1] + 1) - a[pos - 1] - 1;
		}
	}
	while (!check()) a[n]++;
	cout << '!' << ' ';
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}