#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n, ans, f[maxn + 10], g[maxn + 10], a[maxn + 10];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) f[i] =(a[i] == a[i - 1])?f[i-1]+1:1;
	int num1=0,num2=0;
	num1+=n;
	for (int i = n; i >= 1; --i) g[i] = a[i] == a[i + 1] ? g[i + 1] + 1 : 1;
	for (int i = 1; i < n; ++i)
		if (a[i] != a[i + 1]) ans = max(ans, min(f[i], g[i + 1]) * 2);
	printf("%d", ans);
}