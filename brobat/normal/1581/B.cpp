    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define endl "\n"
    #define forn(i, a, n) for (int i = a; i < n; i++)

    const int MAXN = 200100;
    const int MOD = 1000000007;

    void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        if(m < n - 1 || m > n*(n-1)/2) {
            cout << "NO" << endl;
            return;
        }
        if(n==1 && m==0 && k>=2) {
            cout << "YES" << endl;
            return;
        }
        if(m == n*(n-1)/2) {
            if(k>=3) cout << "YES";
            else cout << "NO";
        }
        else {
            if(k>=4) cout << "YES";
            else cout << "NO";
        }
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