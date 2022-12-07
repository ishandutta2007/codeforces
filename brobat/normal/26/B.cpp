#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    int a = 0;
    int ans = 0;
    forn(i, 0, s.length()) {
        if(s[i]=='(') a++;
        else if(a > 0) a--;
        else ans++;
    }
    ans += max(0ll, a);
    cout << s.length() - ans;
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