#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

int check(vector <int> &v, int n, int s) {
    int x = v[s];
    for(int i = s; i < n; i += 2) {
        x = __gcd(x, v[i]);
    }
    if(x == 1) return 0;
    for(int i = !s; i < n; i += 2) {
        if(v[i] >= x) {
            if(v[i] % x == 0) {
                x /= __gcd(v[i], x);
            }
        }
        if(x == 1) return 0;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    // First check for even places
    int a = check(v, n, 1);
    int b = check(v, n, 0);
    if(a) cout << a << endl;
    else cout << b << endl;
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