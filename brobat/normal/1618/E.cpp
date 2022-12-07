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
    vector <int> v(n);
    vector <int> ans(n, 0);
    forn(i, 0, n) cin >> v[i];
    bool pos = true;
    int sum = accumulate(v.begin(), v.end(), 0ll) * 2 / (n * (n + 1));
    // v[i] = ans[i] + 2*ans[i-1] + 3*ans[i-2] + ... n*ans[(i - n + n) mod n + 1]
    // v[i] = sum((j + 1) * ans[(i - j + n)mod(n)])
    // v[i] - v[i - 1] = sum - ans[i] + (1 - n)(ans[i])
    // v[i] - v[i - 1] = sum - n*ans[i]
    // ans[i] = (sum + v[i - 1] - v[i]) / n. If not divisible, ans = NO
    forn(i, 0, n) {
        int x = sum + v[i == 0 ? n - 1 : i - 1] - v[i];
        if(x % n != 0 || x < n) {
            pos = false;
            break;
        }
        ans[i] = x / n;
    }
    int check = 0;
    forn(i, 0, n) check += (i + 1) * ans[(n - i)%n];
    if(check != v[0]) pos = false;
    if(pos) {
        cout << "YES" << endl;
        forn(i, 0, n) cout << ans[i] << " ";
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
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