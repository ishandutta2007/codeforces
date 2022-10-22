#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e5+3, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n,m;
		scanf ("%d %d",&n,&m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) printf ("W");
				else printf ("B");
			}
			printf ("\n");
		}
	}
    return 0;
}