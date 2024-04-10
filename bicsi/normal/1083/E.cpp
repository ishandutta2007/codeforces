#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

using T = long long;

bool QUERY;
struct Line {
	mutable T a, b, p;
  T Eval(T x) const { return a * x + b; }
	bool operator<(const Line& o) const {
		return QUERY ? p < o.p : a < o.a;
	}
};

struct LineContainer : multiset<Line> {
	// for doubles, use kInf = 1/.0, div(a, b) = a / b
	const T kInf = numeric_limits<T>::max();
	T div(T a, T b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = kInf; return false; }
		if (x->a == y->a) x->p = x->b > y->b ? kInf : -kInf;
		else x->p = div(y->b - x->b, x->a - y->a);
		return x->p >= y->p;
	}
	void InsertLine(T a, T b) {
		auto nx = insert({a, b, 0}), it = nx++, pv = it;
		while (isect(it, nx)) nx = erase(nx);
		if (pv != begin() && isect(--pv, it))
      isect(pv, it = erase(it));
		while ((it = pv) != begin() && (--pv)->p >= it->p)
			isect(pv, erase(it));
	}
	T EvalMax(T x) {
		assert(!empty());
		QUERY = 1; auto it = lower_bound({0,0,x}); QUERY = 0;
		return it->Eval(x);
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    vector<tuple<int, int, int>> pts;
    for (int i = 0; i < n; ++i) {
        int x, y, a; cin >> x >> y >> a;
        pts.emplace_back(x, y, a);
    }

    vector<long long> dp(n, 0);
    sort(pts.begin(), pts.end());

    LineContainer lc;
    for (int i = 0; i < n; ++i) {
        int x, y, a; tie(x, y, a) = pts[i];
        dp[i] = 1LL * x * y - a;   
        long long qry = (i == 0 ? 0 : lc.EvalMax(y));
        dp[i] += max(0LL, qry);
        lc.InsertLine(-x, dp[i]); 
//        cerr << x << " " << y << " -> " << dp[i] << endl;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << endl;


    return 0;
}