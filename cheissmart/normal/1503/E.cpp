#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5050, M = 998244353;

int C[N][N];

void add(int& a, int b) {
    a += b;
    if(a >= M) a -= M;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

    C[0][0] = 1;
    for(int i = 1; i < N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }

    int n, m;
    cin >> n >> m;
    int ans = 0;
    auto X = [&] (int i, int j) { return (ll) C[n - i + m - j - 1][n - i] * C[n - i - 1 + j][j] % M; };
    auto Y = [&] (int i, int j) { return (ll) C[i + j - 1][i] * C[m - j + i - 1][i - 1] % M; };
    for(int _ = 0; _ < 2; _++) {
        for(int i = 1; i < n; i++) {
            int pre = 0;
            for(int j = 1; j < m; j++) {
                int x = X(i, j), y = Y(i, j);
                // cerr << i << " " << j << ": " << x << " " << y << '\n';
                add(ans, (ll) pre * x % M);
                add(pre, y);
            }
        }
        swap(n, m);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int x = X(i, j), y = Y(i, j);
            add(ans, (ll) x * y % M);
        }
    }
    add(ans, ans);
    cout << ans << '\n';


}