#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    map<int, int> r, c;
    int cnt_r = 0, cnt_c = 0;
    int cnt = 0;
    vector <pair<int, int>> query(q);
    for(int i = 0; i < q; i++) {
        cin >> query[i].first >> query[i].second;
    }
    for(int i = q - 1; i >= 0; i--) {
        bool yes = false;
        if(r[query[i].first] == 0) {
            yes = true;
            r[query[i].first] = 1;
            cnt_r++;
        }
        if(c[query[i].second] == 0) {
            yes = true;
            c[query[i].second] = 1;
            cnt_c++;
        }
        if(yes) cnt++;
        if(cnt_r == n || cnt_c == m) {
            break;
        }
    }
    cout << binpow(k, cnt) << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}