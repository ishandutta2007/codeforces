#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

int ans[N];
int main() {
	//freopen("in.txt", "r", stdin);
	
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	
	if (n % __gcd(a, b)) return puts("-1"), 0;
	int na = -1, nb = -1;
	for (int i = 0; i * a <= n; i++) {
		int x = n - i * a;
		if (x % b == 0) {
			na = i, nb = x / b;
			break;	
		}
	}
	if (na == -1) return puts("-1"), 0;
	
	for (int i = 1; i <= na; i++)
		for (int j = 1; j <= a; j++) {
			int x = (i - 1) * a + j + 1;
			ans[(i - 1) * a + j] = (j == a ? x - a : x);
		}
	int cur = na * a;	
	for (int i = 1; i <= nb; i++)
		for (int j = 1; j <= b; j++) {
			int x = (i - 1) * b + j + 1;
			ans[(i - 1) * b + j + cur] = (j == b ? x - b + cur : x + cur);
		}
	
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}