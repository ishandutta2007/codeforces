#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, LOG = 18, MOD = 1e9+7;
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n;
		scanf ("%d",&n);
		if (n == 1) {
			printf ("-1\n");
			continue;
		}
		printf ("2");
		while (--n) printf ("3");
		printf ("\n");
	}
    return 0;
}