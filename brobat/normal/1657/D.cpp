#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector <int> best(c + 1, 0); // best[cost] = best hi * di for that particular cost.
    for(int i = 0; i < n; i++) {
        int ci, hi, di;
        cin >> ci >> hi >> di;
        best[ci] = max(best[ci], hi * di);
    }
    vector<vector<int>> check(c + 1); // which "best" values to check for that particular cost
    for(int i = 0; i <= c; i++) {
        if(best[i] == 0) continue;
        for(int j = i; j <= c; j += i) {
            check[j].push_back(i);
        }
    }
    vector<int> ans(c + 1, 0); // the highest damage that can be done for the cost in index.
    for(int i = 1; i <= c; i++) {
        ans[i] = ans[i - 1];
        for(auto j : check[i]) {
            ans[i] = max(ans[i], (i/j) * best[j]);
        }
        // cout << ans[i] << " ";
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int h, d;
        cin >> h >> d;
        int x = upper_bound(ans.begin(), ans.end(), h * d) - ans.begin();
        if(x > c) x = -1;
        cout << x << " ";
    }
    
    return 0;
}