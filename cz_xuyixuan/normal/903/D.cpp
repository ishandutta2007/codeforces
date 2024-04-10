/*Compile with C++14*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
#define INF	1e18
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int a[MAXN];
map <int, int> cnt;
int main() {
	int n; read(n);
	long double ans = 0, sum = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), cnt[a[i]]++, sum += a[i];
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]--;
		sum -= a[i];
		ans += sum - (n - i + 0ll) * a[i];
		ans -= cnt[a[i] + 1];
		ans += cnt[a[i] - 1];
	}
	printf("%.0Lf\n", ans);
	return 0;
}