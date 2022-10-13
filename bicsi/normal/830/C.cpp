#include <bits/stdc++.h>

using namespace std;

template<class Func, class Callback, class T>
void recurse(int from, int to, Func f, Callback cb,
             int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		cb(i, to, p);
		i = to; p = q;
	} else {
		int mid = from + (to - from) / 2;
		recurse(from, mid, f, cb, i, p, f(mid));
		recurse(mid + 1, to, f, cb, i, p, q);
	}
}
template<class Func, class Callback>
void ConstantIntervals(int from, int to, Func f, Callback cb) {
	if (to <= from) return;
	int i = from; auto p = f(i), q = f(to - 1);
	recurse(from, to - 1, f, cb, i, p, q);
	cb(i, to, q);
}


int32_t main() {
    int n; cin >> n;
    long long k; cin >> k;
    long long ans = 1;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    auto chk = [&](long long x) {
        long long now = 0;
        for (auto y : a) {
            long long rem = y % x;
            if (rem) now += x - rem;
        }
        if (now <= k) {
            ans = max(ans, x);
            return true;
        }
        return false;
    };

    vector<long long> vals = {(long long)2e15};
    for (auto y : a) {
        ConstantIntervals(1, (int)2e9, [&](int x) { return y / x; },
                [&](int lo, int hi, int val) { vals.push_back(lo); });
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    

    for (int i = 1; i < (int)vals.size(); ++i) {
        long long lo = vals[i - 1], hi = vals[i];
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (chk(mid)) lo = mid + 1;
            else hi = mid;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}