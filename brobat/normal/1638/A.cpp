#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
// const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    int left = n - 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i].first) continue;
        left = i;
        break;
    }
    vector<vector<int>> p;
    p.push_back(a);
    for(int j = left + 1; j < n; j++) {
        vector <int> c(n);
        forn(k, 0, n) c[k] = a[k];
        reverse(c.begin() + left, c.begin() + j + 1);
            p.push_back(c);
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
        cout << p[0][i] << " ";
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
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}