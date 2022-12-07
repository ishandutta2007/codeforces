#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];
    string p; cin >> p;
    map<string, vector<int>> mp;
    forn(i, 0, n) {
        forn(j, 0, m) {
            if(j >= 1) mp[v[i].substr(j - 1, 2)] = {j, j + 1, i + 1};
            if(j >= 2) mp[v[i].substr(j - 2, 3)] = {j - 1, j + 1, i + 1};
        }
    }
    vector <int> dp(m, -1);
    if(m >= 2 && mp[p.substr(0, 2)].size() > 0) dp[1] = 2;
    if(m >= 3 && mp[p.substr(0, 3)].size() > 0) dp[2] = 3;
    forn(i, 3, m) {
        if(dp[i - 2] != -1 && mp[p.substr(i - 1, 2)].size() > 0) dp[i] = 2;
        if(dp[i - 3] != -1 && mp[p.substr(i - 2, 3)].size() > 0) dp[i] = 3; 
    }
    vector<vector<int>> ans;
    int x = m - 1;
    if(dp[x] == -1) {
        cout << -1 << endl;
        return;
    }
    while(x >= 0) {
        if(dp[x] == 2) {
            ans.push_back(mp[p.substr(x - 1, 2)]);
            x -= 2;
        }
        else {
            ans.push_back(mp[p.substr(x - 2, 3)]);
            x -= 3;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto i : ans) cout << i[0] << " " << i[1] << " " << i[2] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}