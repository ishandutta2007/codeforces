    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define endl "\n"
    #define forn(i, a, n) for (int i = a; i < n; i++)

    const int MAXN = 200100;
    const int MOD = 1000000007;

    void solve() {
        int n, d, g;
        cin >> n >> d;
        g = __gcd(n, d);
        vector <int> v(n);
        map <int, vector<int>> m;
        forn(i, 0, n) cin >> v[i];
        forn(i, 0, g) {
            int x = (i + n - d) % n; m[i].push_back(v[i]);
            // Start at v[i]. Keep making shifts until reaching v[i] again. Finally, double the vector.
            while(x != i) {
                m[i].push_back(v[x]);
                x = (x + n - d) % n;
            }
            int c = m[i].size();
            forn(j, 0, c) m[i].push_back(m[i][j]);
        }
        int ans = 0;
        bool pos = true;
        for(auto i : m) {
            // Find the max number of consecutive 1s in this sequence.
            vector <int> temp;
            int count = 0;
            for(auto j : i.second) {
                if(j == 0) {
                    temp.push_back(count);
                    count = 0;
                }
                else count++;
            }
            temp.push_back(count);
            int x = *max_element(temp.begin(), temp.end());
            if(x == i.second.size()) pos = false;
            ans = max(ans, x);
        }
        if(!pos) cout << -1 << endl;
        else cout << ans << endl;
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