#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

int find(string &s, int i) {
    int x = 0;
    x += (s[2*i] == '1' ? 2 : 0);
    x += (s[2*i + 1] == '1' ? 1 : 0);
    return x;
}

pair<int, int> fmin(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;
    if(a.second < b.second) return a;
    return b;
}

pair<int, int> add(pair<int, int> a, int b, int c) {
    return {a.first + b, a.second + c};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        pair<int, int> dp[n/2][2];
        int st = find(s, 0);
        if(st == 1 || st == 2) {
            dp[0][0] = dp[0][1] = {1, 1};
        } else if(st == 0) {
            dp[0][0] = {0, 1};
            dp[0][1] = {2, 1};
        } else {
            dp[0][0] = {2, 1};
            dp[0][1] = {0, 1};
        }
        for(int i = 1; i < n/2; i++) {
            int st = find(s, i);
            if(st == 0) {
                dp[i][0] = fmin(add(dp[i - 1][0], 0, 0), add(dp[i - 1][1], 0, 1));
                dp[i][1] = fmin(add(dp[i - 1][0], 2, 1), add(dp[i - 1][1], 2, 0));
            } else if(st == 1 || st == 2) {
                dp[i][0] = fmin(add(dp[i - 1][0], 1, 0), add(dp[i - 1][1], 1, 1));
                dp[i][1] = fmin(add(dp[i - 1][0], 1, 1), add(dp[i - 1][1], 1, 0));
            } else {
                dp[i][0] = fmin(add(dp[i - 1][0], 2, 0), add(dp[i - 1][1], 2, 1));
                dp[i][1] = fmin(add(dp[i - 1][0], 0, 1), add(dp[i - 1][1], 0, 0));
            }
        }
        pair<int, int> ans = fmin(dp[n/2 - 1][0], dp[n/2 - 1][1]);
        cout << ans.first << '\n';
    }    
    
    return 0;
}