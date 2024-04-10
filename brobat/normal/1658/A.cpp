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
    string s;
    cin >> s;
    int ans = 0;
    int cnt = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(cnt == -1) {
                cnt = i;
            } else {
                if(i - cnt == 1) ans += 2;
                else if(i - cnt == 2) ans += 1;
                cnt = i;
            }
        }
    }
    cout << ans << endl;
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