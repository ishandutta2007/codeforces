#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
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
int n, m, d[MAXN];
bool ans[MAXN];
vector <int> a[MAXN];
int f(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += n / i - 1;
	return ans;
}
int main() {
	read(n), read(m);
	if (f(n) < m) {
		printf("No\n");
		return 0;
	}
	while (f(n / 2) >= m) n /= 2;
	for (int i = 1; i <= n; i++)
	for (int j = i + i; j <= n; j += i)
		d[j]++;
	for (int i = 1; i <= n; i++)
		ans[i] = true;
	for (int i = n / 2 + 1; i <= n; i++)
		a[d[i]].push_back(i);
	m = f(n) - m;
	for (int i = n; i >= 1; i--)
	for (unsigned j = 0; j < a[i].size(); j++)
		if (m >= i) {
			m -= i;
			ans[a[i][j]] = false;
		}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += ans[i];
	printf("Yes\n%d\n", sum);
	for (int i = 1; i <= n; i++)
		if (ans[i]) printf("%d ", i);
	return 0;
}