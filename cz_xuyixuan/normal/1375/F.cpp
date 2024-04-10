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
ll a[4]; int res;
void getres(int &res) {
	cin >> res;
	if (res == 0) exit(0);
}
ll gety() {
	ll Max = 0, ans = 0;
	for (int i = 1; i <= 3; i++)
		chkmax(Max, a[i]);
	for (int i = 1; i <= 3; i++)
		if (Max == a[i]) ans += a[i] * 2;
		else ans -= a[i];
	return ans;
}
int main() {
	read(a[1]), read(a[2]), read(a[3]);
	puts("First");
	int x = 1e9 + 7; cout << x << endl;
	getres(res); a[res] += x;
	ll y = gety(); cout << y << endl;
	getres(res); a[res] += y;
	sort(a + 1, a + 4);
	assert(a[2] - a[1] == a[3] - a[2]);
	cout << a[2] - a[1] << endl;
	getres(res), assert(false);
	return 0;
}