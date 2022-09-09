#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int n;
int getans(int pos) {
	cout << '?' << ' ' << pos << endl;
	int x; cin >> x;
	if (pos <= n / 2) cout << '?' << ' ' << pos + n / 2 << endl;
	else cout << '?' << ' ' << pos - n / 2 << endl;
	int y; cin >> y;
	return x - y;
}
int main() {
	cin >> n;
	if (n % 4 == 2) {
		cout << '!' << ' ' << -1 << endl;
		return 0;
	}
	int l = 1, vl = getans(l), r = n / 2 + 1, vr = -vl;
	if (vl == 0) {
		cout << '!' << ' ' << l << endl;
		return 0;
	}
	while (true) {
		int mid = (l + r) / 2;
		int tmp = getans(mid);
		if (tmp == 0) {
			cout << '!' << ' ' << mid << endl;
			return 0;
		}
		if (tmp < 0 && vl < 0) l = mid, vl = tmp;
		else if (tmp > 0 && vl > 0) l = mid, vl = tmp;
		else r = mid, vr = tmp;
	}
	return 0;
}