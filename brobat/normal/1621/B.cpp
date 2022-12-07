#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    v.resize(n);
    forn(i, 0, n) v[i].resize(3);
    vector <int> ans(n);
    int first = 0; 
    int last = 0;
    int alone = 0;
    cin >> v[0][0] >> v[0][1] >> v[0][2];
    ans[0] = v[0][2];
    forn(i, 1, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        if(v[i][0] < v[first][0]) {
            first = i;
        }
        else if(v[i][0] == v[first][0]) {
            if(v[i][2] < v[first][2]) {
                first = i;
            }
        }
        if(v[i][1] > v[last][1]) {
            last = i;
        }
        else if(v[i][1] == v[last][1]) {
            if(v[i][2] < v[last][2]) {
                last = i;
            }
        }
        if(v[i][1] - v[i][0] > v[alone][1] - v[alone][0]) {
            alone = i;
        }
        else if(v[i][1] - v[i][0] == v[alone][1] - v[alone][0]) {
            if(v[i][2] < v[alone][2]) {
                alone = i;
            }
        }
        if(v[last][1] - v[first][0] == v[alone][1] - v[alone][0]) {
            ans[i] = min(v[first][2] + v[last][2], v[alone][2]);
        }
        else if(v[last][1] - v[first][0] > v[alone][1] - v[alone][0]) {
            ans[i] = v[last][2] + v[first][2];
        }
        else {
            ans[i] = v[alone][2];
        }
    }
    forn(i, 0, n) cout << ans[i] << endl;
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