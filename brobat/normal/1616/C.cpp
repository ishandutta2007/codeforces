#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

const double EPS = 1E-6;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    if(n <= 2) {
        cout << 0 << endl;
        return;
    }
    int ans = n;
    forn(i, 0, n) {
        forn(j, i + 1, n) {
            double d = (v[i]-v[j])*1.0/(i-j);
            double a = v[i] - i*d;
            int cnt = 0;
            forn(k, 0, n) {
                if(abs(v[k] - (a + k*d)) > EPS) {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
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
    while(T--) solve();

    return 0;
}