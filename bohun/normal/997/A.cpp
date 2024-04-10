#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;
 
int n, X, y;
char s[300005]; 
 
int main() {
	scanf ("%d%d%d", &n, &X, &y);
	scanf ("%s", s + 1);
	int group = 0;
	int ze = 0;
	int je = 0;
	for (int i = 1; i <= n;) {
		int j = i;
		while (j <= n && s[i] == s[j])
			j++;
		group++;
		if (s[i] == '1') je++;
		else ze++;
		i = j;
	}
	
	LL best = 1e18;
	bool d = (ze > je);
	rep(i, 0, n + 1) {
		if ((group - 2 * i + d) / 2 <= 0) break;
		best = min(best, (LL) i * X + (LL) ((group - 2 * i + d) / 2) * y);
	}
	if (group == 1 && je == 1 && ze == 0) best = 0LL;
	printf ("%lld", best);
	
	return 0;
}