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
#define li pair<long, int>
#define iii pair<ii, int>

int n, k;
ve<iii> a;

multiset<int> rr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].xx.xx, &a[i].xx.yy);
        a[i].yy = i;
    }

    sort(a.begin(), a.end());
    li ans(0, -1);
    for (int i = 0; i < n; ++i) {
        rr.insert(a[i].xx.yy);
        if (sz(rr) == k) {
            ans = max(ans, li((long)*rr.begin() - a[i].xx.xx + 1, i));
        }
        while (sz(rr) >= k) rr.erase(rr.begin());
    }

    cout << ans.xx << '\n';
    if (ans.yy != -1) {
        long ml = a[ans.yy].xx.xx + ans.xx - 1;
        for (int i = ans.yy; i >= 0 and k > 0; -- i) {
            if (a[i].xx.yy >= ml) {
                printf("%d ", a[i].yy + 1);
                --k;
            }
        }
    } else {
        for (int i = 1; i <= k; ++i) printf("%d ", i);
    }

    return 0;
}