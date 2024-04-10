#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100000 + 10;
int w, n, m;
ll a[maxn];

ll ad[maxn * 2] = {};
bool ok(ll x) {
    memset(ad, 0, sizeof ad);
    ll used = 0;
    for(int i = 1; i <= n; ++i) {
        ad[i] += ad[i-1];

        if(a[i] + ad[i] < x) {
            ll del = x - (a[i] + ad[i]);
            used += del;
            ad[i] += del;
            ad[i+w] -= del;
        }
    }

    return used <= m;
}

int main() {
    scanf("%d%d%d", &n, &m, &w);
    for(int i = 1, t; i <= n; ++i) {
        scanf("%d", &t); a[i] = t;
    }

    ll l = 1, r = 1600000000, ans = 1;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) { ans = mid; l = mid + 1; }
        else r = mid - 1;
    }

    cout << ans << endl;

    return 0;
}