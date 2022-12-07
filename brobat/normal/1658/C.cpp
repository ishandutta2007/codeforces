#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    int ind = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == 1) {
            ind = i;
            cnt++;
        }
    }
    if(cnt != 1) {
        cout << "NO" << endl;
        return;
    }
    vector <int> w;
    for(int i = ind; i < n; i++) {
        w.push_back(v[i]);
    }
    for(int i = 0; i < ind; i++) {
        w.push_back(v[i]);
    }
    for(int i = 1; i < n; i++) {
        if(w[i] - w[i - 1] > 1) {
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