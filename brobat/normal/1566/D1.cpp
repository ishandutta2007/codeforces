#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    map<int, int> mp;
    forn(i, 0, m) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), comp);
    forn(i, 0, m) mp[v[i].second] = i;
    vector<int> t(m, 0);
    int ans = 0;
    for(auto i : mp) {
        // Fill seat i.second
        forn(j, 0, i.second) if(t[j]==1) ans++;
        t[i.second] = 1;
    }
    cout << ans << endl;
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