#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using T = long double;

struct Line {
    int idx;
	T a, b, p;
    T Eval(T x) const { return a * x + b; }
};

double Inter(Line a, Line b) {
    return (a.b - b.b) / (b.a - a.a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<T> v(n), pref(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; v[i] = x;
        pref[i] = v[i];
        if (i > 0) pref[i] += pref[i - 1];
    }

    vector<int> dp(n);

    vector<Line> stk;
    stk.push_back(Line{n, -1.0 * n, pref[n - 1], 1e18});
    for (int i = n - 1; i >= 0; --i) {
        Line now{i, -1.0 * i, i == 0 ? 0. : pref[i - 1], 0.};
        while (true) {
            auto p = Inter(now, stk.back());
            if (p > stk.back().p) {
                stk.pop_back();
            } else break;
        }
        now.p = Inter(now, stk.back());
        dp[i] = stk.back().idx;
        stk.push_back(now);
    }
    
    
    cout << fixed << setprecision(20);
    int i = 0;
    while (i < n) {
        T sum = 0, cnt = 0;
        int j = dp[i];
        for (int k = i; k < j; ++k) {
            sum += v[k];
            cnt += 1;
        }
        for (int k = i; k < j; ++k) {
            cout << sum / cnt << "\n";
        }
        i = j;
    }
    // cout << endl;

    return 0;
}