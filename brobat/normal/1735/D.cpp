#include <bits/stdc++.h>
using namespace std;

vector<int> xor3(vector<int> &a, vector<int> &b) {
    int k = a.size();
    vector <int> ans(k);
    for(int i = 0; i < k; i++) {
        ans[i] = (3 - a[i] - b[i] + 9) % 3;
    }
    return ans;
}

void print(vector<int> &a) {
    cout << "{";
    for(auto i : a) cout << i << ',';
    cout << "}";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> v[i][j];
        }
    }
    vector <long long> dp(n, 0);
    sort(v.begin(), v.end());
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(i == j) continue;
    //         auto x = xor3(v[i], v[j]);
    //         auto it = lower_bound(v.begin(), v.end(), x);
    //         int ind = it - v.begin();
    //         if(it == v.end() || (*it) != x || ind == i || ind == j) continue;
    //         print(v[i]); print(v[j]); print(x); cout << '\n';
    //         dp[i]++;
    //     }
    // }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            // print(v[i]);
            // cout << ' ';
            // print(v[j]);
            // cout << ' ';
            auto x = xor3(v[i], v[j]);
            auto it = lower_bound(v.begin(), v.end(), x);
            int ind = it - v.begin();
            if(ind >= j || (*it) != x) continue;
            // print(v[i]); print(v[j]); print(x); cout << '\n';
            dp[i]++;
            dp[j]++;
            dp[ind]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += 1ll*dp[i]*(dp[i] - 1)/2;
    }
    cout << ans << '\n';
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << ' ';
    // }
    
    return 0;
}