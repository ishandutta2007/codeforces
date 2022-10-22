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
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

LL a, b;
vector <LL> qw;

int main() {
	scanf ("%lld %lld", &a, &b);
	if (!a && !b) {
		printf ("0\n");
		return 0;
	}
	LL c = (a ^ b);
	if (c == 0) {
		printf ("1\n%lld\n", a);
	}
	else if ((b - a) % 2 == 1 || a > b) printf ("-1\n");
	else {
		c = b - a;
		qw.pb(a);
		qw.pb(c / 2);
		qw.pb(c / 2);
		if (a + c / 2 == (a ^ c / 2)) {
			qw.pop_back();
			qw[0] += c / 2;
		}
		printf ("%d\n", ss(qw));
		for (auto it : qw) printf ("%lld ", it);
	}
		
	return 0;
}