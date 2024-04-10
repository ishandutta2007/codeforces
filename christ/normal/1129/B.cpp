#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
ll stupid (int n, vector<int> a) {
	ll ret = 0, cur = 0, k = -1;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		if (cur < 0) {
			cur = 0;
			k = i;
		}
		ret = max(ret,(i-k)*cur);
	}
	return ret;
}
ll good (int n, vector<int> &a) {
	ll ret = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			ret = max(ret,(j-i+1)*sum);
		}
	}
	return ret;
}
int main() { //a = # of -1s, b = final number, diff = a(b-1-a)
	int n;
	scanf ("%d",&n);
	if (n <= 1e6) return !printf ("1\n%d\n",-n);
	for (int a = 0; a < 2e3-1; a++) {
		for (int c = 0; c < a; c++) {
			int go = a*a-a*c+2*a-2*c+n;
			if (go%(a+1)) continue;
			int b = go/(a+1);
			if (b < 1 || a >= b || b > 1e6) continue;
			vector<int> ret = {c};
			for (int i = 0; i < a; i++) ret.push_back(-1);
			ret.push_back(b);
			assert(good(a+2,ret)-stupid(a+2,ret) == n);
			printf ("%d\n",ret.size());
			for (int i : ret) printf ("%d ",i);
			printf ("\n");
			return 0;
		}
	}
	printf ("-1\n");
    return 0;
}