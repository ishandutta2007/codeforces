%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define For(i, l, r) rep(i, l, r - 1)

void read(int &x) {
    x = 0; int f = 1;
    char op = getchar();
    while (!isdigit(op)) {
        if (op == '-') f = -1;
        op = getchar();
    }
    while (isdigit(op)) {
        x = 10 * x + op - '0';
        op = getchar();
    }
    x *= f;
}

long long n, m, ans = 1e18, id = 0;

int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		long long a, b; scanf("%lld%lld",&a,&b);
		long long qaq = a + b * ((m - a - 1) / b + 1);
		if (a >= m) qaq = a;
		if (qaq - m < ans) ans = qaq - m, id = i;
	}
	printf("%d\n", id);
	return 0;
}