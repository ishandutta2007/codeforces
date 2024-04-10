#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    ll h; int n;
	scanf ("%lld %d",&h,&n);
	vector<int> a(n); vector<ll> psa; ll mn = 0;
	for (auto &au : a) {
		scanf ("%d",&au);
		psa.push_back((psa.empty()?0:psa.back())+au);
		mn = min(mn,psa.back());
	}
	ll sum = psa.back();
	if (h+mn <= 0) {
		for (int i = 0; i < n; i++) if (h+psa[i] <= 0) return !printf ("%d\n",i+1);
	} else if (sum >= 0) return !printf ("-1\n");
	//h+mn+sum*x <= 0
	//sum*x <= -h-mn
	//x >= -(h+mn)/sum
	ll togo = (-(h+mn))/sum;
	while (h+mn+sum*togo > 0) ++togo;
	h += sum * togo;
	ll ans = n * 1LL * togo;
	if (h <= 0) return !printf ("%lld\n",ans);
	else {
		for (int i = 0; i < n; i++) if (h+psa[i] <= 0) return !printf ("%lld\n",ans+i+1);
	}
	assert(0);
    return 0;
}