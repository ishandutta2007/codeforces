#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[111];
ll n, h;

bool check(ll k) {
    ll s = h, i;
    for (i = 1; i <= n && s > 0; i++) {
        if (i == n || A[i] + k < A[i + 1]) s -= k;
        else s -= (A[i + 1] - A[i]);
    }
    return s <= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, i, s, e, m;
    
    for (cin >> t; t--; ) {
        cin >> n >> h;
        for (i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (s = 1, e = 1e18; s <= e; ) {
            m = s + e >> 1;
            if (check(m)) e = m - 1;
            else s = m + 1;
        }
        cout << s << "\n";
    }
    
    return 0;
}