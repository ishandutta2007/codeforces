#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5 + 5, MOD = 1e9 + 7;
int main () {
	int n,e,d;
	scanf ("%d %d %d",&n,&d,&e);
	int ret = n;
	for (int dollar = 0; dollar * 1LL * d <= n; dollar++) {
		int sofar = dollar * d;
		int left = n - sofar;
		int cantake = (left) / (5 * e);
		left -= cantake * 5 * e;
		ret = min(ret,left);
	}
	printf ("%d\n",ret);
	return 0;
}