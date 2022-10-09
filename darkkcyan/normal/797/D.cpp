#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace sol {
// solution start here
int n;
vi a, b, l, r, p;

long ans = 0;
void dfs(int i, int ll, int rr) {
    if (i < 0) {
        ans += rr - ll;
        return;
    }

    int mid1 = lower_bound(b.begin() + ll, b.begin() + rr, a[i]) - b.begin();
    int mid2 = upper_bound(b.begin() + ll, b.begin() + rr, a[i]) - b.begin();

    dfs(l[i], ll, mid1);
    dfs(r[i], mid2, rr);
}

int main() {
    srand(time(0));
    cin >> n;
    a.resize(n, -1);
    p = l = r = a;
    //clog << "start" << endl;
    rep(i, n) {
        cin >> a[i] >> l[i] >> r[i];
        --l[i], --r[i];
        if (l[i] >= 0) p[l[i]] = i;
        if (r[i] >= 0) p[r[i]] = i;
    }

    b = a;
    sort(b.begin(), b.end());

    rep(i, n) {
        if (p[i] != -1) continue;
        dfs(i, 0, n);
        break;
    }
    cout << ans;
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}