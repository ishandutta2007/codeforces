#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int func(int val, int x, int y) {
    // For some operations, decrease the lowest value by 1.
    // Then set the last Y elements equal to first element.
    // Return the minimum number of operations to do so
    // Let answer be k
    // (k - y) operations reduce the last element
    // At this point, the value val is increased by y*(k - y)
    // The rest y operations decrease this value to 0
    // So the sum is reduced by (k - y) + val + y*(k - y).
    // We want this ^^ to be >= x and (k - y) >= 0.
    // Find minimum value of k st. this using binary search
    // 
    // t*(y+1) + val >= x; t >= 0.
    // t >= (x - val)/(y + 1).
    int c = (x - val)/(y + 1);
    while(c*(y + 1) < (x - val)) c++;
    if(c < 0) c = 0;
    return c + y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    int x = accumulate(v.begin(), v.end(), 0ll) - k;
    if(x <= 0) {
        cout << 0 << endl;
        return;
    }
    sort(v.begin(), v.end());
    vector <int> suff(n + 1, 0);
    {
        vector <int> temp(n);
        forn(i, 1, n) temp[i] = v[i] - v[0];
        // forn(i, 1, n) cout << temp[i] << " ";
        // cout << endl;
        suff[n] = 0;
        for(int i = n - 1; i >= 1; i--) suff[i] = suff[i + 1] + temp[i];
    }
    // forn(i, 1, n + 1) cout << suff[i] << " ";
    // cout << endl;
    int ans = INF;
    forn(i, 1, n + 1) {
        // cout << "For i = " << i << " minimum no of ops is " << func(suff[i], x, n - i) << endl;
        ans = min(ans, func(suff[i], x, n - i));
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