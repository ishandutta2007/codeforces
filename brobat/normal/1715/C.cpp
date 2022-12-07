#include <bits/stdc++.h>
using namespace std;
#define int long long

int n; // actually n + 2, we do padding at corners.
vector <int> v;

int conv_zero(int index) {
    // change at converting value at this index to a 0.
    int ans = 0;
    if(index > 0 && v[index] == v[index - 1]) {
        ans += index; // segments ending at index.
        ans += index * (n - index - 1);
    }
    if(index < n - 1 && v[index] == v[index + 1]) {
        ans += n - index - 1; // segments starting at index.
        ans += index * (n - index - 1);
    }
    v[index] = 0;
    return ans;
}

int conv_back(int index, int val) {
    assert(v[index] == 0);
    int ans = 0;
    if(index > 0 && v[index - 1] == val) {
        ans += index;
        ans += index * (n - index - 1);
    }
    if(index < n - 1 && v[index + 1] == val) {
        ans += n - index - 1;
        ans += index * (n - index - 1);
    }
    v[index] = val;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> n >> q;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 1;
    vector <int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] != v[i - 1]) {
            dp[i] = dp[i - 1] + 1 + i;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
        ans += dp[i];
    }
    // cout << ans << '\n';
    for(int i = 0; i < q; i++) {
        int ind, x;
        cin >> ind >> x;
        --ind;
        ans += conv_zero(ind);
        ans -= conv_back(ind, x);
        cout << ans << '\n';
    }
    
    return 0;
}