#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = -1;
    vector <int> x(n);
    forn(i, 0, n) cin >> x[i];
    vector<string> s(n);
    forn(i, 0, n) cin >> s[i];
    vector <int> perm(m);
    forn(i, 0, 1<<n) {
        vector<pair<int, int>> v(m);
        int r = 0;
        forn(j, 0, m) v[j] = {j, 0};
        for(int j = 0; j < n; j++) {
            int b = (i >> (n - 1 - j)) & 1;
            if(b) {
                r -= x[j];
                forn(k, 0, m) {
                    if(s[j][k] == '1') v[k].second++;
                }
            }
            else {
                r += x[j];
                forn(k, 0, m) {
                    if(s[j][k] == '1') v[k].second--;
                }
            }
        }
        sort(v.begin(), v.end(), comp); // Now index --> points of the question - 1.
        unordered_map<int, int> mp;
        forn(j, 0, m) {
            mp[v[j].first] = j + 1;
            r += (v[j].second) * (j + 1);
        }
        if(ans < r) {
            for(auto i : mp) perm[i.first] = i.second;
            ans = r;
        }
    }
    for(auto i : perm) cout << i << " ";
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