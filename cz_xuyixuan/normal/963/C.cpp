#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
long long getgcd(long long x, long long y) {
	if (x == 0 || y == 0) return x + y;
	else return getgcd(y, x % y);
}
struct info {long long x, y, cnt; };
bool cmpx(info a, info b) {return a.x < b.x; }
bool cmpy(info a, info b) {return a.y < b.y; }
info a[MAXN];
long long s, l, r;
long long f(long long x) {
	long long i = 2, ans = 1;
	while (i * i <= x) {
		int cnt = 1;
		while (x % i == 0) {
			x /= i;
			cnt++;
		}
		ans *= cnt;
		i++;
	}
	if (x != 1) ans *= 2;
	return ans;
}
int main() {
	int n; read(n);
	s = 0, l = 1;
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y), read(a[i].cnt), s += a[i].cnt;
	r = s;
	sort(a + 1, a + n + 1, cmpx);
	for (int i = 1; i <= n; i++)
		if (a[i].x != a[i - 1].x) {
			long long sum = 0, gcd = 0;
			for (int j = i; a[j].x == a[i].x; j++) {
				sum += a[j].cnt;
				gcd = getgcd(gcd, a[j].cnt);
			}
			r = getgcd(r, sum);
			long long now = sum / gcd;
			long long tmp = getgcd(now, l);
			now /= tmp;
			if (l > r / now) {
				printf("0\n");
				return 0;
			} else l *= now;
		}
	sort(a + 1, a + n + 1, cmpy);
	for (int i = 1; i <= n; i++)
		if (a[i].y != a[i - 1].y) {
			long long sum = 0, gcd = 0;
			for (int j = i; a[j].y == a[i].y; j++) {
				sum += a[j].cnt;
				gcd = getgcd(gcd, a[j].cnt);
			}
			long long tmp = s / getgcd(s, sum), tnp = getgcd(tmp, l);
			tmp /= tnp;
			if (l > r / tmp) {
				printf("0\n");
				return 0;
			} else l *= tmp;
			long long now = sum / gcd;
			if (s % now != 0) {
				printf("0\n");
				return 0;
			}
			now = s / now;
			r = getgcd(now, r);
		}
	if (r % l != 0) printf("0\n");
	else printf("%lld\n", f(r / l));
	return 0;
}