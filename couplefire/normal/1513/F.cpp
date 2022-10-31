#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 2e5 + 5;
const ll inf = 1e16;

struct node {
	ll l, r; int type;
	node(ll _l = 0, ll _r = 0, int _type = 0) {
		l = _l; r = _r; type = _type;
	}
};

int n;
ll a[maxn], b[maxn];
vector<node> p;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);

	ll sum = 0;
	for(int i=1;i<=n;i++) {
		int type = 0;
		if(a[i] <= b[i]) type += 1;
		if(a[i] >= b[i]) type += 2;
		p.push_back(node(min(a[i],b[i]), max(a[i],b[i]), type));
		sum += abs(a[i] - b[i]);
	}

	ll mx, res;
	ll ans = inf;

	// solve for a
	sort(p.begin(), p.end(), [](node x, node y) {
		if(x.l != y.l) return x.l < y.l;
		return (x.type & 2) > (y.type & 2);
	});
	mx = res = 0;
	for(auto t : p) {
		if((t.type & 2) != 0) mx = max(mx, t.r);
		if((t.type & 1) != 0) res = max(res, min(mx, t.r) - t.l);
	}
	ans = min(ans, sum - 2LL * res);

	// solve for b
	sort(p.begin(), p.end(), [](node x, node y) {
		if(x.l != y.l) return x.l < y.l;
		return (x.type & 1) > (y.type & 1);
	});
	mx = res = 0;
	for(auto t : p) {
		if((t.type & 1) != 0) mx = max(mx, t.r);
		if((t.type & 2) != 0) res = max(res, min(mx, t.r) - t.l);
	}
	ans = min(ans, sum - 2LL * res);

	printf("%lld",ans);
}