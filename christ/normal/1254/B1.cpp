#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int main() {
	int n; scanf ("%d",&n);
	vector<int> a(n+1); int sum = 0;
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), sum += a[i];
	ll ret = LLONG_MAX, what = -1;
	auto check = [&] (int go) {
		vector<int> cur; ll att = 0;
		for (int i = 1; i <= n; i++) if (a[i]) {
			cur.push_back(i);
			if (cur.size() == go) {
				int mid = cur[cur.size()/2];
				for (int j : cur) att += abs(j-mid);
				cur.clear();
			}
		}
		assert(!cur.size());
		if (att < ret) {
			ret = att;
			what = go;
		}
	};
	for (int div = 2; div * div <= sum; div++) if (sum%div==0){
		check(div);
		check(sum/div);
	}
	if (sum != 1) check(sum);
	printf ("%lld\n",ret>1e18?-1:ret);
    return 0;
}