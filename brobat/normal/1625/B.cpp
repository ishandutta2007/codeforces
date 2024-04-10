#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 150100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    map<int, vector<int>> m;
    forn(i, 0, n) {
        cin >> v[i];
        m[v[i]].push_back(i + 1);
    }
    int ans = -1;
    for(auto i : m) {
        if(i.second.size() < 2) continue;
        int x = i.second.size();
        int a, b, st, nd;
        forn(j, 0, x - 1) {
            a = i.second[j];
            b = i.second[j + 1];
            st = b - a + 1;
            ans = max(ans, n - st + 1);
            swap(a, b);
            a = n - a + 1;
            b = n - b + 1;
            st = b - a + 1;
            ans = max(ans, n - st + 1);
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}