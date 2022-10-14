#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n, m; cin >> n >> m;
    vector<ll> k(n);
    rep(i, n) cin >> k[i];
    sort(k.begin(),k.end());
    if(k.size() == 1) {
        rep(i, m) {
            ll v; cin >> v;
            cout << k[0]+v << " \n"[i==m-1];
        }
    } else {
        ll g = 0;
        rep1(i, n-2) {
            // if(k[i+1]-k[i]) cerr << k[i+1]-k[i] << endl;
            if(g == 0) g = k[i+1] - k[i];
            else if(k[i+1] - k[i]) g = __gcd(g, k[i+1] - k[i]);
        }
        // cerr << g << endl;
        rep(i, m) {
            ll v; cin >> v;
            if(g) cout << __gcd(k[0]+v, g) << " \n"[i==m-1];
            else cout << k[0]+v << " \n"[i==m-1];
        }
    }
    return 0;
}