#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool balanced(int l, int r, string& s) {
    int a = 0, b = 0;
    forn(i, l, r + 1) {
        if(s[i]=='a') a++;
        else b++;
    }
    return a==b;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    forn(i, 0, n) forn(j, i+1, n) {
        if(balanced(i, j, s)) {
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
    return;
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