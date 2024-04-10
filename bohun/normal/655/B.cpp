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

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n, k;
LL ans;
			

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, min(k, n / 2)) {
		ans += 1 + 2 * (n - 2 * i);
	}
	printf ("%lld\n", ans);
	
	return 0;
}