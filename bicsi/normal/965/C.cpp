#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int int64_t

using namespace std;

template<typename Pred>
int Search(Pred pred) {
    int ans = 0;
    for (int step = (1LL << 60); step; step /= 2) {
        if (pred(ans + step) == 0)
            ans += step;
    }
    return ans + 1;
}

template<class Func, class Callback, class T>
void recurse(int from, int to, Func f, Callback cb,
        int& i, T& p, T q) {
    if (p == q) return;
    if (from == to) {
        cb(i, to, p);
        i = to; p = q;
    } else {
        int mid = (from + to) / 2;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m, d; cin >> n >> k >> m >> d;

    auto get = [&](int x) {
        int times = n / x;
        int times_me = (times + k - 1) / k;
        return times_me;
    };
    int lo = Search([&](int x) { return get(x) <= d; });
    int hi = m + 1;

    int best = 0;
    ConstantIntervals(lo, hi, get, [&](int lo, int hi, int val) {
        best = max(best, (hi - 1) * val);
    });
    cout << best << endl;

    return 0;
}