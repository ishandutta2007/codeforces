#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int steps[1010];
int mx_w = 0;

void pre() {
    steps[0] = 0;
    steps[1] = 0;
    forn(i, 2, 1010) steps[i] = i - 1;
    for(int i = 1; i < 1010; i++) {
        // steps[i] is known at this step.
        // Use it to minimise steps j
        for(int j = 1; j <= i; j++) {
            int k = i + (i/j);
            if(k >= 1010) continue;
            steps[k] = min(steps[k], steps[i] + 1);
        }
    }
    forn(i, 0, 1010) mx_w = max(mx_w, steps[i]);
    cerr << mx_w << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(mx_w * 1001, k); // now k can't be more than 12,000
    int wt[n+1], val[n+1], dp[n+1][k+1];
    forn(i, 0, n) {
        cin >> wt[i];
        wt[i] = steps[wt[i]];
    }
    forn(i, 0, n) cin >> val[i];
    forn(j, 0, k + 1) {
        if(wt[0] > j) dp[0][j] = 0;
        else dp[0][j] = val[0];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(wt[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], val[i] + dp[i-1][j - wt[i]]);
        }
    }
    // forn(i, 0, n) {
    //     forn(j, 0, k + 1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n-1][k] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    pre();
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}