#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 100005;
int ans[maxn], n, p, q, now, cur;

int main() {
	cin >> n;
	p = 1; q = n;
	rep (i, 2, n)
		if (i + (n + i - 1) / i < p + q) {
			p = i; q = (n + i - 1) / i;
		}
	rep (i, 1, p) {
		cur = min(n, q * i);
		while (cur && !ans[cur])
			ans[cur--] = ++now;
	}
	rep (i, 1, n)
		printf("%d ", ans[i]);
	return 0;
}