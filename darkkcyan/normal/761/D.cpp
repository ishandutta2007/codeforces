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

int n; long l, r;
ve<long> a, b, p;
vi pos;

bool cmppos(int u, int v) { return p[u] < p[v]; }

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    a.resize(n); p.resize(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> p[i];

    pos.resize(n);
    for (int i = 0; i < n; ++i) pos[i] = i;
    sort(pos.begin(), pos.end(), cmppos);

    long lo = l - r;
    b.resize(n);
    for (int f = 0; f < n; ++f) {
        int i = pos[f];
        b[i] = max(l, lo + a[i]);
        if (b[i] > r) {
            cout << -1;
            exit(0);
        }
        lo = b[i] - a[i] + 1;
    }

    for (int i = 0; i < n; ++i) cout << b[i] << ' ';

    return 0;
}