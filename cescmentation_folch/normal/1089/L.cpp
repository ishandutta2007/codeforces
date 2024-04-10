#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    VI a(n);
    vector<ii> b(n);
    ll p = 0;
    vector<ll> v(k, 0);
    for (ll i = 0; i < n; ++i){
        cin >> a[i];--a[i];
        v[a[i]]++;
    }
    for (ll i = 0; i < n; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }
    
    sort(b.begin(), b.end());
    
    ll ans = 0;
    for (ll i = 0; i < n and p != k; ++i){
        while (p < k and v[p] != 0) ++p;
        if (p < k){
            ll val = a[b[i].second];
            if (v[val] > 1){
                --v[val];
                ++v[p];
                ans += b[i].first;
            }
        }
    }
    cout << ans << endl;
}