#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, q;
    cin >> n >> q;
    char t;
    int sum[n];
    sum[0] = 0;
    forn(i, 1, n+1) {
        cin >> t;
        if(t=='+') {
            if(i%2==0) {
                sum[i] = sum[i-1] + 1;
            }
            else {
                sum[i] = sum[i-1] - 1;
            }
        }
        else {
            if(i%2==0) {
                sum[i] = sum[i-1] - 1;
            }
            else {
                sum[i] = sum[i-1] + 1;
            }
        }
    }
    // forn(i, 0, n) cout << sum[i] << " ";
    forn(i, 0, q) {
        int a, b;
        cin >> a >> b;
        int x = sum[b] - sum[a-1];
        if(x==0) cout << 0 << endl;
        else if(x % 2 == 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
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