#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int solve() {
    int x, y;
    cin >> x >> y;
    int d = x*x + y*y;
    int e = sqrt(d);
    if(d == 0) return 0;
    if(e * e == d) return 1;
    return 2;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        cout << solve() << endl; 
    }

    return 0;
}