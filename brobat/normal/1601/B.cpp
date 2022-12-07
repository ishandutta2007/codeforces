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
    vector <int> a(n + 1), b(n + 1), dist(n + 1, -1), p(n + 1, -1);
    int done = n; dist[n] = 0; p[n] = 0;
    forn(i, 1, n + 1) cin >> a[i];
    forn(i, 1, n + 1) cin >> b[i];
    for(int i = n; i > 0; i--) {
        int k = i + b[i];
        for(int j = done - 1; j >= k - a[k]; j--) {
            if(dist[j] == -1) {
                dist[j] = dist[k - b[i]] + 1;
                p[j] = k - b[i];
            }
        }
        done = min(done, k - a[k]);
    }
    cout << dist[0] << endl;
    int temp = 0;
    vector <int> ans;
    while(p[temp] > 0) {
        ans.push_back(temp);
        temp = p[temp];
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i << " ";
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