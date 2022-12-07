#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1000100;
const int MOD = 1000000007;

int n, t1, m;
vector<vector<int>> v;
map<vector<int>, char> b;
vector <int> ans;
int curr_max;

bool first_check() {
    vector <int> f(n);
    forn(i, 0, n) {
        f[i] = v[i].size();
    }
    if(!b[f]) return true;
    return false;
}

void solve() {
    cin >> n;
    curr_max = 0;
    ans.resize(n);
    v.resize(n);
    forn(i, 0, n) {
        cin >> t1;
        v[i].resize(t1);
        forn(j, 0, t1) cin >> v[i][j];
    }
    // forn(i, 0, n) forn(j, 0, v[i].size()) cout << v[i][j] << " ";/
    cin >> m;
    forn(i, 0, m) {
        vector <int> v(n);
        forn(j, 0, n) cin >> v[j];
        b[v] = true;
    }
    if(first_check()) {
        forn(i, 0, n) cout << v[i].size() << " ";
        return;
    }
    for(auto f : b) {
        if(f.second == false) continue;
        auto banned = f.first;
        forn(j, 0, n) {
            vector <int> t(n);
            forn(i, 0, n) {
                if(i==j) t[i] = max(1ll, banned[i] - 1);
                else t[i] = banned[i];
            }
            if(!b[t]) {
                int a = 0;
                forn(i, 0, n) a += v[i][t[i] - 1];
                if(a > curr_max) {
                    curr_max = a;
                    ans = t;
                }
            }
        }
    }
    for(auto i : ans) cout << i << " ";
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