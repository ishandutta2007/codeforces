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
    vector <int> m(n), k(n);
    forn(i, 0, n) cin >> m[i] >> k[i];
    vector <vector<int>> store(min(20ll, n));
    vector <double> exp;
    for(int i = 1; i <= min(20ll, n); i++) {
        // Assume that we need to choose i messages.
        unordered_map <int, int> sum;
        forn(j, 0, n) {
            sum[m[j]] += min(k[j], i);
        }
        vector<pair<int, int>> v;
        int cnt = 0;
        for(auto j : sum) {
            v.push_back(j);
            cnt++;
        }
        if(cnt < i) break;
        sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        int x = 0;
        forn(j, 0, i) {
            store[i - 1].push_back(v[j].first);
            x += v[j].second;
        }
        exp.push_back(x * 1.0 / i);
    }
    int ind = max_element(exp.begin(), exp.end()) - exp.begin();
    cout << store[ind].size() << endl;
    for(auto i : store[ind]) cout << i << " ";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}