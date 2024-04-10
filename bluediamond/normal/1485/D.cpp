#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 500 + 7;
const int E = 720 * 1001;
int n, m, a[N][N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        cin >> a[i][j];
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                        if ((i + j) & 1)
                                cout << E;
                        else
                                cout << E + a[i][j] * a[i][j] * a[i][j] * a[i][j];
                        cout << " ";
                }
                cout << "\n";
        }

}