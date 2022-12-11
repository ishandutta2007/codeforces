#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

const ll INF = 4.1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n, l, r;
        ull x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        //cerr << "eps" << endl;
        vector<ull> b(n);
        VI a(n);
        b[0] = b1; b[1] = b2;
        const ll mod = 1LL << 32;
        for (int i = 2; i < n; ++i) b[i] = (b[i-2]*x%mod + b[i-1]*y%mod + z)%mod;
        ll ans = INF;
        ll mespetit = INF;
        stack<ll> negs;
        for (int i = 0; i < n; ++i){
            a[i] = (ll(b[i]) %(r-l+1)) + l;
            if (a[i] >= 0 and mespetit < a[i]){
                ans = min(ans, mespetit*a[i]);
            }
            else if (a[i] < 0){
                while (not negs.empty() and negs.top() < a[i]){
                    ans = min(ans, a[i]*negs.top());
                    negs.pop();
                }
                negs.push(a[i]);
            }
            if (a[i] < mespetit) mespetit = a[i];
        }
        
        if (ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    
}