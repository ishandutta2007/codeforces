#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll solve(ll x, ll m) {
    if (x < 2*m) return 2;
    return (x+m-1)/m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TT;
    cin >> TT;
    set<int> st;
    while (TT--) {
        st.clear();
        ll n, x;
        cin >> n >> x;
        for (int i=0; i<n; ++i) {
            ll y;
            cin >> y;
            st.insert(y);
        }
        if (st.count(x)) {
            cout << 1 << "\n";
        } else {
            auto it = st.upper_bound(x);
            ll p = 1e9+1;
            if (it != st.end()) {
                ll m = *it;
                p = solve(x, m);
            }
            if (it != st.begin()) --it;
            ll m = *it;
            ll q = solve(x, m);
            cout << min(q, p) << "\n";
        }
        
    }
    return 0;
}