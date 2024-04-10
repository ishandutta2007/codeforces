
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
 
signed main() {
    int n; cin >> n;
    rep(i, n) {
        rep(j, n) {
            ll d = 1ull<<(i+j);
            if(i % 2 == 0) cout << d;
            else cout << 0;
            cout << ' ';
        }
        cout << endl; cout.flush();
    }
    int q; cin >> q;
    while(q--) {
        ll v; cin >> v;
        assert(v % 2 == 1);
        v /= 2;
        int x = 0, y = 0;
        cout << x+1 << ' ' << y+1 << endl; cout.flush();
        while(x != n-1 || y != n-1) {
            if(x % 2 == 0) {
                if(v % 2) y++;
                else x++;
            } else {
                if(v % 2) x++;
                else y++;
            }
            v /= 2;
            cout << x+1 << ' ' << y+1 << endl; cout.flush();
        }
    }
}