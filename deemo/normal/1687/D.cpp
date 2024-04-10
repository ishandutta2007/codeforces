#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 10;

int n;
ll a[MAXN], b[MAXN];
ll ta[MAXN], tb[MAXN];

bool is_good(int i) {
    return a[i] - b[i]*b[i] <= b[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    n = unique(a, a + n) - a;

    ll cur = 1;
    for (int i = 0; i < n; i++) {
        while ((cur+1)*(cur+1) <= a[i]) cur++;
        b[i] = cur;
    }

    cur = 0;
    if (!is_good(0)) {
        b[0]++;
        cur = b[0]*b[0]-a[0];
        for (int i = 0; i < n; i++)
            a[i] += cur;
    }

    while (true) {
        for (int i = 0; i < n; i++)
            if ((b[i]+1)*(b[i]+1) <= a[i])
                b[i]++;

        int sz = 1;
        ta[0] = a[0], tb[0] = b[0];
        for (int i = 1; i + 1 < n; i++)
            if (!(b[i-1] == b[i] && b[i] == b[i+1] && is_good(i) == is_good(i-1) && is_good(i) == is_good(i+1)))
                ta[sz] = a[i], tb[sz] = b[i], sz++;
        ta[sz] = a[n-1], tb[sz] = b[n-1], sz++;
        n = sz;
        memcpy(a, ta, sizeof(ll) * n);
        memcpy(b, tb, sizeof(ll) * n);

        int mx = 1e9, mn = -1;
        for (int i = 0; i < n; i++)
            if (is_good(i))
                mx = min((ll)mx, b[i] - (a[i] - b[i]*b[i]));
            else
                mn = max((ll)mn, (b[i]+1)*(b[i]+1)-a[i]);

        if (mn == -1) break;
        if (mn <= mx) {
            cur += mn;
            break;
        }
        
        cur += mn;
        for (int i = 0; i < n; i++)
            a[i] += mn;
    }

    cout << cur << "\n";
    return 0;
}