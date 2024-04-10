#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SZ(a) ((int)a.size())

const int N = 1e5 + 5;
int a[N];
double lg[N], dp[N][10];
pii pi[N][10]; // yn / prv

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i], lg[i] = log(a[i]);
    for (int i = 0; i < 10; i++)
        dp[0][i] = -1e18;
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)
            dp[i + 1][j] = -1e18;
        for (int j = 0; j < 10; j++)
            if (dp[i][j] >= 0) {
                int x = (j * a[i + 1]) % 10;
                if (dp[i][j] + lg[i + 1] > dp[i + 1][x])
                    dp[i + 1][x] = dp[i][j] + lg[i + 1], pi[i + 1][x] = {1, j};
                if (dp[i][j] > dp[i + 1][j])
                    dp[i + 1][j] = dp[i][j], pi[i + 1][j] = {0, j};
            }
    }
    if (dp[n][d] < 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    int cur = d;
    for (int i = n; i > 0; i--) {
        if (pi[i][cur].X)
            v.pb(a[i]);
        cur = pi[i][cur].Y;
    }
    if (SZ(v) == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << SZ(v) << "\n";
    for (int i = 0; i < SZ(v); i++)
        cout << v[i] << " \n"[i == SZ(v) - 1];
}