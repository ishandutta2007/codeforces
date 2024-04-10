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

ve<ii> p;

ii operator+(const ii& a, const ii& b) { return ii(a.xx + b.xx, a.yy + b.yy); }
ii operator-(const ii& a, const ii& b) { return ii(a.xx - b.xx, a.yy - b.yy); }

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ii a[3];
    for (int i = 0; i < 3; ++i) scanf("%d%d", &a[i].xx, &a[i].yy);
    for (int i = 0; i < 3; ++i) {
        int f = (i + 1) % 3, g = (f + 1) % 3;
        ii t = a[g] - a[f];
        p.push_back(a[i] + t);
        p.push_back(a[i] - t);
    }

    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    printf("%d\n", sz(p));
    for (int i = 0; i < sz(p); ++i) printf("%d %d\n", p[i].xx, p[i].yy);

    return 0;
}