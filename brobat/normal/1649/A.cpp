#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int left = 0;
    int right = n - 1;
    for(int i = 1; i < n; i++) {
        if(v[i] == 1) left++;
        else break;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(v[i] == 1) right--;
        else break;
    }
    cout << max(right - left, 0ll) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}