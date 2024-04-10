#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);

string s, t;

inline bool read() {
    if(!(cin >> s >> t))
        return false;
    for(auto &c : s)
        c -= 'a';
    for(auto &c : t)
        c -= 'a';
    return true;
}

vector< vector<int> > nxt;

bool calc(const string &a, const string &b) {
    vector< vector<int> > dp(sz(a) + 1, vector<int>(sz(b) + 1, INF));
    dp[0][0] = 0;
    fore(i, 0, sz(a) + 1) fore(j, 0, sz(b) + 1) {
        if(dp[i][j] > sz(s))
            continue;
        
        int len = dp[i][j];
        if(i < sz(a) && nxt[len][a[i]] < INF) {
            dp[i + 1][j] = min(dp[i + 1][j], nxt[len][a[i]] + 1);
        }
        if(j < sz(b) && nxt[len][b[j]] < INF) {
            dp[i][j + 1] = min(dp[i][j + 1], nxt[len][b[j]] + 1);
        }
    }
    return dp[sz(a)][sz(b)] < INF;
}

inline void solve() {
    nxt.assign(sz(s) + 1, vector<int>(26, INF));
    for(int i = sz(s) - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i]] = i;
    }
    
    for(int i = 0; i < sz(t); i++) {
        if(calc(t.substr(0, i), t.substr(i, sz(t)))) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    int tc; cin >> tc;
    
    while(tc--) {
        read();
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}