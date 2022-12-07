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
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    int ans = 0;
    deque <int> c;
    for(int i = 1; i < n - 1; i++) {
        if(v[i] > v[i - 1] && v[i] > v[i + 1]) {
            c.push_back(i);
        }
    }
    while(!c.empty()) {
        if((int)c.size() >= 2) {
            int x = c[0];
            int y = c[1];
            if(y - x == 2) {
                v[x + 1] = max(v[x], v[y]);
                ans++;
                c.pop_front();
                c.pop_front();
            } else {
                v[x + 1] = v[x];
                ans++;
                c.pop_front();
            }
        } else {
            ans++;
            v[c[0] + 1] = v[c[0]];
            c.pop_front();
        }
    }
    cout << ans << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
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