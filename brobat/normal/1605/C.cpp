#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.find("aa") < n) {
        cout << 2 << endl;
    }
    else if(s.find("aca") < n || s.find("aba") < n) {
        cout << 3 << endl;
    }
    else if(s.find("acba") < n || s.find("abca") < n) {
        cout << 4 << endl;
    }
    else if(s.find("abbacca") < n || s.find("accabba") < n) {
        cout << 7 << endl;
    }
    else {
        cout << -1 << endl;
    }
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