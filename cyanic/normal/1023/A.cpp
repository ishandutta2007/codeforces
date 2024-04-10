#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 200005;
char s[maxn], t[maxn];
int n, m, p;

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	if (n > m + 1) return puts("NO"), 0;
	rep (i, 1, n)
		if (s[i] == '*') {
			p = i; break;
		}
	if (!p) {
		if (n != m) return puts("NO"), 0;
		rep (i, 1, n)
			if (s[i] != t[i])
					return puts("NO"), 0;
		puts("YES");
		return 0;
	}
	rep (i, 1, p - 1)
		if (s[i] != t[i])
			return puts("NO"), 0;
	rep (i, 1, n - p)
		if (s[n+1-i] != t[m+1-i])
			return puts("NO"), 0;
	puts("YES");
	return 0;
}