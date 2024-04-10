#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef double ld;

const int MAXN = 2e3 + 10;

int n, P, Q;
ld p[MAXN], q[MAXN];
pair<ld, int> d[MAXN][MAXN];

pair<ld, int> get(ld mid) {
    for (int i = 0; i < n; i++)
        for (int t = 0; t <= P; t++) {
            d[i + 1][t] = d[i][t];
            if (t)
                d[i+1][t] = max(d[i+1][t], {d[i][t-1].F + p[i], d[i][t-1].S});
            d[i+1][t] = max(d[i+1][t], {d[i][t].F + q[i] - mid, d[i][t].S - 1});
            if (t)
                d[i+1][t] = max(d[i+1][t], {d[i][t-1].F + p[i] + (1 - p[i]) * q[i] - mid, d[i][t-1].S - 1});
        }
    return {d[n][P].F, -d[n][P].S};
}

int main() {
    cout << fixed << setprecision(12);
    cin >> n >> P >> Q;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    
    ld lo = 1e-9, hi = 2e3 + 5;
    while (clock() < CLOCKS_PER_SEC * 4.8) {
        ld mid = (hi + lo) / 2;
        if (get(mid).S > Q)
            lo = mid;
        else
            hi = mid;
    }
    auto x = get(hi);
    cout << x.F + hi * Q << "\n";
    return 0;
}