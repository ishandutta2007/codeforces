
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
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int mx = 0;
        rep(i, n) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        bool ok = 0;
        rep(i, n) if(a[i] != mx) ok = 1;
        if(ok) cout << 1 << endl;
        else cout << n << endl;
    }
}