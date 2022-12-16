#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll a, b, d;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    if(a > b) {
        swap(a, b);
    }
    if(a == b) {
        cout << 0 << endl;
        return 0;
    }
    d = b-a;
    vector<int> fac;
    for(int i=1; i*i<=d; ++i) {
        if(d%i == 0) {
            fac.push_back(i);
            if(i*i != d) fac.push_back(d/i);
        }
    }
    pii ans(1e18, 0);
    for(auto& x : fac) {
        ll k = ((a+x-1)/x)*x-a;
        //cerr << " k = " << k << " for x = " << x<< endl;
        ans = min(ans, pii((a+k)*(b+k)/__gcd(d, a+k), k));
    }
    cout << ans.second << endl;
    return 0;
}