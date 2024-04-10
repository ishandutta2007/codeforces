#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back


ll dp[405][405], c[405][405], pw[405];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, M;
    cin >> n >> M;

    for (int i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < n; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * 2 % M;

    for (int i = 1; i <= n; i++) {
        dp[i][i] = pw[i - 1];
        for (int j = 1; j < i; j++)
            for (int k = 1; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - k - 1][j - k] * pw[k - 1] % M * c[j][k]) % M;
    }

    ll total = 0;
    for (int i = 0; i <= n; i++)
        total = (total + dp[n][i]) % M;
    cout << total << endl;
}