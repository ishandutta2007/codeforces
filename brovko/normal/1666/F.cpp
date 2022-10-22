#include <bits/stdc++.h>

using namespace std;
using li = long long;

const li INF64 = 1e18 + 13;
const int N = 5000 + 13;
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int f[N], inv[N];
int a[N];

int suff[N], sufinv[N];
int dp[N][N];

void solve() {
    int n;
    cin >> n;

    vector<int> c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0 || a[i] != a[i - 1])
            c.push_back(0);
        c.back()++;
    }

    int m = c.size();

    vector<int> p(m + 1, 0);
    for(int i = 0; i < m; i++) {
        p[i + 1] = p[i] + c[i];
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n / 2; j++)
            dp[i][j] = 0;
        suff[i] = 0;
        sufinv[i] = 0;
    }

    suff[m] = sufinv[m] = 1;
    for(int i = m - 1; i >= 0; i--) {
        suff[i] = mul(suff[i + 1], f[c[i]]);
        sufinv[i] = mul(sufinv[i + 1], inv[c[i]]);
    }

//    for(int i = 0; i < m; i++)
//        cout << c[i] << ' ';
//    cout << endl;
//
//    for(int i = 0; i <= m; i++)
//        cout << suff[i] << ' ';
//    cout << endl;
//
//    for(int i = 0; i <= m; i++)
//        cout << sufinv[i] << ' ';
//    cout << endl;

    for(int j = 1; j <= n / 2; j++) {
        int pref = 0;
        for(int i = 0; i < m; i++) {
            if(i >= j)dp[i][j] = (j == 1 ? mul(mul(p[i], sufinv[0]), mul(suff[i], inv[c[i] - 1])) : mul(pref, mul(suff[i], inv[c[i] - 1])));
            pref = add(pref, mul(mul(dp[i][j - 1], p[i] + 1 - (j - 1) * 2), sufinv[i + 1]));

//            if(j == 1 && i == 2) {
//                cout << "asd faw f " << p[i] << ' ' << sufinv[0] << ' ' << suff[i] << ' ' << inv[c[i] - 1] << endl;
//            }
        }
    }

//    for(int i = 0; i < m; i++) {
//        for(int j = 0; j <= n / 2; j++)
//            cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    cout << dp[m - 1][n / 2] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
        inv[i] = pow2(f[i], MOD - 2);
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}