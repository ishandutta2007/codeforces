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
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    int a = 0, b = 0;
    if(n % 2 == 0) {
        for(int i = 0; i <= (n - 1)/2; i++) a += v[i];
        for(int i = 0; i < n/2 - 1; i++) b += v[n - i - 1];
        cout << (a >= b ? "NO" : "YES") << endl;
        return;
    }
    for(int i = 0; i <= (n - 1)/2; i++) a += v[i];
    for(int i = 0; i < n/2; i++) b += v[n - i - 1];
    cout << (a >= b ? "NO" : "YES") << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}