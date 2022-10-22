#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	map<int,int> cnt; ll psum = a[0]; ld ret = 0; cnt[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		ret += (ld)a[i]*i-psum;
		ret -= cnt[a[i]-1];
		ret += cnt[a[i]+1];
		psum += a[i];
		++cnt[a[i]];
	}
	printf ("%.0Lf\n",ret);
    return 0;
}