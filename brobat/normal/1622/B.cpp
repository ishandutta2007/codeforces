#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first;
        v[i].second = i;
    }
    string s; cin >> s;
    vector <pair<int, int>> a, b;
    forn(i, 0, n) {
        if(s[i] == '1') b.push_back(v[i]);
        else a.push_back(v[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <int> ans(n);
    int cnt = 1;
    for(auto i : a) ans[i.second] = cnt++;
    for(auto i : b) ans[i.second] = cnt++;
    for(auto i : ans) cout << i << " ";
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