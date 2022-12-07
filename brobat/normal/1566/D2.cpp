#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, m;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> v(m*n);
    map<int, pair<int, int>> mp;
    forn(i, 0, m*n) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), comp);
    forn(i, 0, m*n) mp[v[i].second] = {v[i].first, i};
    vector<int> t(m*n, -1);
    int ans = 0;
    for(auto i : mp) {
        int k = (i.second.second / m) * m;
        forn(j, k, i.second.second) if(t[j] != -1 && t[j] != i.second.first) ans++;
        t[i.second.second] = i.second.first;
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