#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 200005;
int n, ans, f;
char s[maxn];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep (i, 1, n)
		s[i+n] = s[i];
	ans = f = 1;
	rep (i, 2, 2 * n) {
		if (s[i] != s[i-1]) f++;
		else f = 1;
		ans = max(ans, f);
	}
	ans = min(ans, n);
	printf("%d\n", ans);
	return 0;
}