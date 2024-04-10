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
    vector <int> temp(n);
    forn(i, 0, n) cin >> temp[i];
    vector <int> b, r;
    char c;
    forn(i, 0, n) {
        cin >> c;
        if(c=='B') b.push_back(temp[i]);
        else r.push_back(temp[i]);
    }
    bool pos = true;
    sort(b.begin(), b.end());
    sort(r.begin(), r.end(), greater<int>());
    int it = 1;
    forn(i, 0, b.size()) {
        if(b[i] < it) {
            pos = false;
            break;
        }
        it++;
    }
    it = n;
    forn(i, 0, r.size()) {
        if(r[i] > it) {
            pos = false;
            break;
        }
        it--;
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
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