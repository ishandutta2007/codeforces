#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, m;
ve<ii> a;
void read() {
    scanf("%d%d", &n, &m);
    a.resize(m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &a[i].xx, &a[i].yy),
        --a[i].xx, --a[i].yy;
}

bool cmpr(const ii& a, const ii& b) {
    int t = a.yy - a.xx - b.yy + b.xx;
    if (t == 0) return a.xx < b.xx;
    return t < 0;
}

long mex;
ve<long> ans;
void process() {
    sort(a.bb, a.ee, cmpr);
    mex = a[0].yy - a[0].xx + 1;
    ans.resize(n, -1);
    for (int i = a[0].xx; i <= a[0].yy; ++i) {
        ans[i] = i - a[0].xx;
    }
    for (int i = a[0].xx - 1; i >= 0; --i) {
        ans[i] = ans[i + mex];
    }
    for (int i = a[0].yy + 1; i < n; ++i)
        ans[i] = ans[i - mex];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    process();
    cout << mex << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';

    return 0;
}