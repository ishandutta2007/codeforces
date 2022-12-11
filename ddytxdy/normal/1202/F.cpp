#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a, b, n, ans;
int main() {
	scanf("%d%d", &a, &b); n = a + b;
	for (int i = 1; i <= n; i++) {
		int l = i, g = n / l, r = n / g;
		int mna = ceil(1.0 * a / (g + 1)), mxa = a / g;
		int mnb = ceil(1.0 * b / (g + 1)), mxb = b / g;
		if (mxa >= mna && mxb >= mnb)ans += min(mxa + mxb, r) - max(mna + mnb, l) + 1;
		i = r;
	}
	printf("%d\n", ans);
	return 0;
}