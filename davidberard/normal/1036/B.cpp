#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    for(int i=0;i<q;++i) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll mn = max(n, m);
        ll diag = max(n, m) - (min(n, m)%2 != max(n, m)%2);
        ll ord = (min(n, m)%2 != max(n, m)%2);
        ll extra = k - max(n, m);
        if(k < mn) {
            cout << -1 << "\n";
            continue;
        }
        if(extra%2) {
            if(ord) {
                ++diag;
            } else {
                --diag;
            }
            --extra;
        }
        cout << extra+diag << "\n";
    }
    return 0;
}