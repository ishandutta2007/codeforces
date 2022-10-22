#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e3 + 5, MOD = 1e9 + 7;
int a[MN][MN];
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf ("%d",&a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int other = 1 + (i == 1);
		int other2 = 2 + (i <= 2);
		printf ("%lld ",(ll)roundl(sqrtl(a[i][other] * 1LL * a[i][other2] / a[other][other2])));
	}
	printf ("\n");
	return 0;
}