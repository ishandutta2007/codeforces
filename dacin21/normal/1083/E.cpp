#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



struct Line {
	ll k, m;
	mutable ll p;
	bool operator<(const Line& o) const {
		return k < o.k;
	}
	bool operator<(const ll&x) const {
		return p < x;
	}
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = numeric_limits<ll>::max();
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<LL, pair<LL, LL> > > aa(n);
	for(int i = 0; i < n; i++){
		cin >> aa[i].first >> aa[i].second.first >> aa[i].second.second;
	}
	sort(aa.begin(), aa.end());
	LineContainer lc;
	lc.add(0, 0);
	LL ans = 0;
	for(int i = 0; i < n; i++){
		LL x = aa[i].first;
		LL y = aa[i].second.first;
		LL a = aa[i].second.second;
		LL f = lc.query(y);
		f += x * y - a;
		lc.add(-x, f);
		ans = max(ans, f);
	}
	cout << ans << '\n';
}