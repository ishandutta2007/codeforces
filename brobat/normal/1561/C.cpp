#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    // first -> power. second -> number.
    forn(i, 0, n) {
        int k;
        cin >> k;
        v[i].second = k;
        v[i].first = 0;
        int tt;
        forn(j, 0, k) {
            cin >> tt;
            if(v[i].first < tt - j) v[i].first = tt - j;
        }
    }
    sort(v.begin(), v.end());
    int p = 0;
    forn(i, 0, n) {
        if(v[i].first >= p) p = v[i].first + 1;
        p += v[i].second;
    }
    for(int i = n-1; i >=0; i--) {
        p -= v[i].second;
    }
    cout << p << endl;
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