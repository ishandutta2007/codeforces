#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, k;
vi a, b;
multiset<ii> t;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    a.resize(n);
    int nc = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[i] = a[i] >= 0, nc += !a[i];
    if (nc > k) cout << -1, exit(0);

    if (nc == 0) cout << 0, exit(0);

    int i = 0;
    for (;i < n and a[i]; ++i);
    b.push_back(1); ++i;
    int time = 1;
    for (; i < n; ++i) {
        if (a[i] == a[i - 1]) ++b.back();
        else b.push_back(1), ++time;
    }

    for (int i = 1; i < sz(b); i += 2)
        t.insert(ii(i == sz(b) - 1 ? -1 : -2, b[i]));
    while (sz(t)) {
        int u = t.begin()->yy, p = -t.begin()->xx; t.erase(t.begin());
        if (u + nc <= k) {
            nc += u;
            time -= p;
        }
    }
    cout << time;
    return 0;
}