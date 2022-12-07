#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, t;
    cin >> n;
    set <pair<int, int>> s;
    forn(i, 0, n) {
        cin >> t;
        if(t==0) continue;
        s.insert({t, i+1});
    }
    vector<pair<int, int>> ans;
    // cout << s.size();
    while(s.size() > 1) {
        auto a = *s.begin();
        auto b = *(--s.end());
        // cout << a.first << " " << b.first << endl;
        s.erase(a);
        s.erase(b);
        ans.push_back({a.second, b.second});
        if(a.first > 1) s.insert({a.first - 1, a.second});
        if(b.first > 1) s.insert({b.first - 1, b.second});
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.first << " " << i.second << endl;
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