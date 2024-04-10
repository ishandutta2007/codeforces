#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;
const int mod = 998244353;

void run() {
    int n; cin >> n;
    vector Cnk(n+1, vector<int>(n+1));
    Cnk[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            Cnk[i][j] += Cnk[i-1][j];
            if (j) {
                Cnk[i][j] += Cnk[i-1][j-1];
                Cnk[i][j] %= mod;
            }
        }
    }
    int r1 = Cnk[n-1][n/2];
    for (int i = 1; n - 4*i >= 0; ++i) {
        r1 += Cnk[n - 4*i][n/2 - (2*i-1)];
        r1 %= mod;
        if (n - 4*i - 1 >= 0) {
            r1 += Cnk[n - 4*i - 1][n/2 - (2*i-1) - 1];
        }
        r1 %= mod;
    }
    cout << r1 << " " << (Cnk[n][n/2] - r1 + mod - 1) % mod << " " << 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}