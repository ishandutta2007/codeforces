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
struct info {int x, y; ll z; };
vector <info> ans;
ll s[MAXN], t[MAXN], p[MAXN], a[MAXN];
bool cmp(int x, int y) {
	return s[x] < s[y];
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(s[i]), p[i] = i;
	for (int i = 1; i <= n; i++)
		read(t[i]);
	sort(t + 1, t + n + 1);
	sort(p + 1, p + n + 1, cmp);
	sort(s + 1, s + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] - t[i];
		sum += a[i];
	}
	if (sum != 0) {
		puts("NO");
		return 0;
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			puts("NO");
			return 0;
		}
		while (a[i] < 0) {
			while (a[pos] <= 0) pos++;
			int d = min(-a[i], a[pos]);
			ans.push_back((info) {p[i], p[pos], d});;
			a[i] += d, a[pos] -= d;
		}
	}
	puts("YES");
	writeln(ans.size());
	for (auto x : ans)
		printf("%d %d %lld\n", x.x, x.y, x.z);
	return 0;
}