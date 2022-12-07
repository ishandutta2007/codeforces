#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int c, d;
    cin >> c >> d;
    if(c==0 && d==0) {
        cout << 0 << endl;
        return;
    }
    int x = abs(c-d);
    if(x==0) {
        cout << 1 << endl;
        return;
    }
    if(x%2==0) {
        cout << 2 << endl;
        return;
    }
    cout << -1 << endl;
    return;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}