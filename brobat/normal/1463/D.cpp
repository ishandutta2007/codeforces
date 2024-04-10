#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vector <int> v(n);
    vector <int> a(2*n + 1, 0);
    forn(i, 0, n) {
        cin >> v[i];
        a[v[i]] = 1;
    }
    // for(auto i : a) cout << i << " ";
    set <int> s, t;
    forn(i, 1, 2*n + 1) {
        if(a[i]==0) {
            s.insert(i);
            t.insert(i);
        }
    }
    // for(auto i : s) cout << i << " ";
    int mn = 0;
    forn(i, 0, n) {
        if(v[i] > *(s.begin())) {
            s.erase(s.begin());
        }
        else {
            mn++;
            s.erase((--s.end()));
        }
    }
    // cout << mn << endl;
    int mx = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] < *(--t.end())) {
            t.erase((--t.end()));
        }
        else {
            mx++;
            t.erase(t.begin());
        }
    }
    mx = n - mx;
    cout << max(0ll, mx - mn + 1) << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}