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
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int x = v[0]/3;
    bool pos = true;
    forn(i, 0, n) if(v[i] % 3 != 0) pos = false;
    if(pos) {
        cout << x << endl;
        return;
    }
    bool one = false;
    bool two = false;
    forn(i, 0, n) {
        if(v[i] % 3 == 1) one = true;
        if(v[i] % 3 == 2) two = true;
    }
    if(!one || !two) {
        cout << x + 1 << endl;
        return;
    }
    if(v[0] % 3 == 0) {
        cout << x + 1 << endl;
        return;
    }
    if(v[0] % 3 == 1) {
        bool pos = true;
        if(v[n - 1] == 1) pos = false;
        forn(i, 0, n) if(v[i] == x*3) pos = false;
        if(pos) {
            cout << x + 1 << endl;
            return;
        }
    }
    cout << x + 2 << endl;
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