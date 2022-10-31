#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e4 + 5, MAXK = 105, inf = (int)1e9 + 123;
int n, K, a[N], dp[N][MAXK], pref[N], suff[N], pter, mx[N];

struct ConvexHull {
    vector<int> A, B;
    void reset () { A.clear(); B.clear(); }
    bool bad (bool _, int l1, int l2, int l3) {
        if (_) return (B[l2] - B[l1]) * (A[l1] - A[l3]) >= (B[l3] - B[l1]) * (A[l1] - A[l2]);
        else return (B[l2] - B[l1]) * (A[l1] - A[l3]) <= (B[l3] - B[l1]) * (A[l1] - A[l2]);
    }
    void add (bool _, int _A, int _B) {
        while (A.size() && _A == A.back() && _B <= B.back() ) A.pop_back(), B.pop_back();
        A.push_back(_A); B.push_back(_B);
        while (A.size() > 2 && bad(_, (int)A.size() - 3, (int)A.size() - 2, (int)A.size() - 1) ) A.erase(A.end() - 2), B.erase(B.end() - 2);
    }
    int f (int x, int _) { return A[_] * x + B[_]; }
    int get (int x) {
        if (!A.size() ) return inf;
        int l = 0, r = (int)A.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(x, mid) < f(x, mid + 1) ) r = mid;
            else l = mid + 1;
        }
        return f(x, l);
    }
} ch;

void solve (int _, int l, int r) {
    if (l == r) return ;

    int mid = (l + r) >> 1;
    solve(_, l, mid); solve(_, mid + 1, r);

    pref[mid + 1] = a[mid + 1];
    for (int i = mid + 2; i <= r; ++i) pref[i] = max(pref[i - 1], a[i]);
    suff[mid] = a[mid];
    for (int i = mid - 1; i >= l; --i) suff[i] = max(suff[i + 1], a[i]);

    for (int j = _; j <= _; ++j) {
        ch.reset(); pter = l;
        for (int i = r; i > mid; --i) {
            while (pter < mid && suff[pter + 1] >= pref[i]) {
                if (dp[pter][j - 1] != inf) ch.add(1, suff[pter + 1], -pter * suff[pter + 1] + dp[pter][j - 1]);
                ++pter;
            }
            dp[i][j] = min(dp[i][j], ch.get(i) );
        }
    }

    for (int j = _; j <= _; ++j) {
        ch.reset(); pter = mid;
        for (int i = mid + 1; i <= r; ++i) {
            while (pter >= l && (pter == mid || suff[pter + 1] <= pref[i]) ) {
                if (dp[pter][j - 1] != inf) ch.add(0, -pter, dp[pter][j - 1]);
                --pter;
            }
            dp[i][j] = min(dp[i][j], ch.get(pref[i]) + i * pref[i]);
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; ++i) cin >> a[i], mx[i] = max(mx[i - 1], a[i]);
    for (int i = 1; i <= n; ++i) dp[i][1] = i * mx[i];
    for (int i = 2; i <= K; ++i) {
        for (int j = 1; j <= n; ++j) dp[j][i] = inf;
        solve(i, 1, n);
    }
    cout << dp[n][K] << endl;
}