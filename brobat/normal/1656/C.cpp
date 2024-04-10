#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    bool z = false;
    bool o = false;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == 0) z = true;
        if(v[i] == 1) o = true;
    }
    if(!o) {
        cout << "YES" << endl;
        return;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++) {
        if(v[i] == v[i - 1] + 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}