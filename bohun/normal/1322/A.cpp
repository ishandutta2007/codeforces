#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

int n;
char s[1000005];

int main() {
	scanf ("%d%s", &n, s + 1);
	int out = 0, b = 0;
	rep(i, 1, n) {
		b += (s[i] == '(' ? 1 : -1);
		if (b < 0 || (!b && s[i] == '('))
			out++;
	}
	if (b != 0) puts("-1\n");
	else printf ("%d\n", out);
		
	return 0;
}