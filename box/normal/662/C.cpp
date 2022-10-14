// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
 
using ll=long long;

using vl=vector<ll>;

vl mult(vl& a, vl& b) {
	assert(a.size() == b.size());
	if(a.size() == 1) return {a[0] * b[0]};
	vl a0(a.begin(), a.begin()+a.size()/2), a1(a.begin()+a.size()/2, a.begin()+a.size());
	vl as(a.size()/2), ad(a.size()/2); rep(i, a.size()/2) as[i] = a0[i] + a1[i], ad[i] = a0[i] - a1[i];
	vl b0(b.begin(), b.begin()+b.size()/2), b1(b.begin()+b.size()/2, b.begin()+b.size());
	vl bs(b.size()/2), bd(b.size()/2); rep(i, b.size()/2) bs[i] = b0[i] + b1[i], bd[i] = b0[i] - b1[i];
	vl x0 = mult(as, bs), x1 = mult(ad, bd), ans(a.size());
	rep(i, a.size()/2) ans[i] = (x0[i] + x1[i]) / 2;
	rep(i, a.size()/2) ans[i+a.size()/2] = (x0[i] - x1[i]) / 2;
	return ans;
}

string tp[20];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
	vl a(1<<n), b(1<<n);
	rep(i, n) cin >> tp[i];
	rep(i, m) {
		string k; rep(j, n) k += tp[j][i];
		a[bitset<20>(k).to_ulong()]++;
	}
	rep(i, 1<<n) {
		int ppc = __builtin_popcount(i);
		b[i] = min(ppc, n-ppc);
	}
	vl c = mult(a, b);
	ll ans = c[0];
	for(ll& t:c) ans = min(ans, t);
	cout << ans;
}