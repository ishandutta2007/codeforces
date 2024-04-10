#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<ll, ll> mll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    mll M;
    M[0] = 1;
    ll S = 0;
    int n;
    ll k;
    cin >> n >> k;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        S += x;
        M[S]++;
        ll t = 1;
        while (t < (ll)1e16) {
//             if (t > 0) {
                res += M[S - t];
//             }
            t *= k;
            
            if (t == 1) break;
        }
    }
    cout << res << '\n';
}