#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e4+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
void solve () {
	int n,d;
	scanf ("%d %d",&n,&d);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	int ret = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] * i <= d) {
			d -= a[i] * i;
			ret += a[i];
		} else {
			ret += d/i;
			d = 0;
		}
	}
	printf ("%d\n",ret);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}