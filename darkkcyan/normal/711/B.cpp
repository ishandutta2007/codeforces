#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    if (n == 1) return cout << 1, 0;

    static ve<ve<long>> a;
    a.resize(n, ve<long>(n));
    int sr, sc;
    for (int i = 0; i < n; ++i) {
        for (int f = 0; f < n; ++f) {
            cin >> a[i][f];
            if (a[i][f] == 0) sr = i, sc = f;
        }
    }

    long sum = accumulate(all(a[0]), (long)0);
    if (sr == 0) sum = accumulate(all(a[1]), (long) 0);
    for (int i = 0 ; i < n; ++i) {
        if (i == sr) continue;
        if (accumulate(all(a[i]), (long)0) != sum) return cout << -1, 0;
    }

    long ans = sum - accumulate(all(a[sr]), (long) 0);
    if (ans <= 0) return cout << -1, 0;

    a[sr][sc] = ans;

    clog << "done";
    long ts = 0;
    for (int i = 0; i < n; ++i) {
        ts = 0;
        for (int f = 0; f < n; ++f) ts += a[f][i];
        if (ts != sum) return cout << -1, 0;
    }

    ts = 0;
    for (int i = 0; i < n; ++i) ts += a[i][i];
    if (ts != sum) return cout << -1, 0;

    ts = 0;
    for (int i = 0; i < n; ++i) ts += a[i][n - i - 1];
    if (ts != sum) return cout << -1, 0;

    cout << ans;

    return 0;
}