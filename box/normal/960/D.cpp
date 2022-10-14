// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

ll b[62];
ll sh[62];

void pr(ll node) {
    int d = 63 - __builtin_clzll(node);
    cout << (node - sh[d]) % b[d] + b[d] << ' ';
    if(d) pr(node/2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    b[0] = 1;
    rep1(i, 61) b[i] = 1ll<<i;
    int q; cin >> q;
    while(q--) {
        int t; ll x; cin >> t >> x;
        int d = 63 - __builtin_clzll(x);
        x = b[d] + (x + sh[d]) % b[d];
        if(t == 1) { 
            ll k;
            cin >> k; 
            k = ((k % b[d]) + b[d]) % b[d]; 
            sh[d] = (sh[d] + k) % b[d];
        }
        if(t == 2) {
            ll k;
            cin >> k; 
            k = ((k % b[d]) + b[d]) % b[d]; 
            iter(dd, d, 62) {
                sh[dd] = (sh[dd] + k) % b[dd];
                k *= 2;
            }
        }
        if(t == 3) {
            //cout << x << endl;
            pr(x);
            cout << endl;
        }
    }
}