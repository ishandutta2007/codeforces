#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n; 
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    forn(i, 1, n) {
        if(ans.size() == 1) {
            if(s[i] < s[i-1]) ans += s[i];
            else break;
        }
        else {
            if(s[i] <= s[i-1]) ans += s[i];
            else break;
        }   
    }
    cout << ans;
    for(int i = ans.length() - 1; i >= 0; i--) cout << ans[i];
    cout << endl;
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