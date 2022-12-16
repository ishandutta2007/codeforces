#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, b;

vector<pii> fac(ll m) {
    vector<pii> ans;
    for(ll i=2;i*i<=m;++i) {
        if(m%i == 0) {
            ll c = 0;
            while(m%i == 0) {
                m/=i;
                ++c;
            }
            ans.emplace_back(i, c);
        }
    }
    if(m != 1) {
        ans.emplace_back(m, 1);
    }
    return ans;
}

ll cfac(ll n, ll f) {
    ll ans = 0;
    ll p = f;
    for(;;p*=f) {
        ans += n/p;
        if(n/p == 0 || f > 1e9 || p > 8e18/f) {
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> b;
    vector<pii> facs = fac(b);
    ll ans = 1e18;
    for(auto& p : facs) {
        ans = min(ans, cfac(n, p.first)/p.second);
        //cerr << " from " << p.first << " we got " << cfac(n, p.first) << " div " << p.second << endl;
    }
    cout << ans << endl;
    return 0;
}