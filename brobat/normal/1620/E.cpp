#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 500001;
const int MOD = 1000000007;

int parent[MAXN];

void solve() {
    int q, t1, t2, t3;
    cin >> q;
    vector<pair<int, int>> query;
    forn(i, 0, q) {
        cin >> t1;
        if(t1 == 1) {
            cin >> t2;
            query.push_back({-1, t2});
        }
        else {
            cin >> t2 >> t3;
            query.push_back({t2, t3});
        }
    }
    forn(i, 0, MAXN) parent[i] = i;
    vector <int> v;
    for(int i = q - 1; i >= 0; i--) {
        if(query[i].first == -1) v.push_back(parent[query[i].second]);
        else parent[query[i].first] = parent[query[i].second];
    }
    for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}