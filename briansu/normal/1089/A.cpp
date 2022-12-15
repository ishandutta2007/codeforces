#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

bool dp[6][205][205][4];
pii pi[6][205][205][6];
void smax(int &a, int b) {
    a = max(a, b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= 200; j++)
            for (int k = 0; k <= 200; k++)
                for (int l = 0; l < 3 && l <= i; l++)
                    if (dp[i][j][k][l]) {
                        if (i - l == 3)
                            continue;
                        int ws = (i == 4 ? 15 : 25);
                        for (int x = 0; x + j <= 200; x++)
                            for (int y = 0; y + k <= 200; y++) {
                                if ((x == ws && y <= ws - 2) || (x >= ws && x == y + 2)
                                 || (y == ws && x <= ws - 2) || (y >= ws && y == x + 2)) {
                                        dp[i + 1][j + x][k + y][l + (x > y)] = 1, pi[i + 1][j + x][k + y][l + (x > y)] = {x, y};
                                 }
                            }
                    }

    // for (int i = 0; i <= 5; i++)
    //     for (int j = 0; j <= 200; j++)
    //         for (int k = 0; k <= 200; k++)
    //             cerr << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int ans = -10, bsti = -1, bstl = -1;
        for (int i = 3; i <= 5; i++) {
            for (int l = 0; l <= 3; l++)
                if ((l == 3 || (i - l) == 3) && dp[i][a][b][l]) {
                    if (l - (i - l) > ans)
                        ans = l - (i - l), bsti = i, bstl = l;
                }
        }
        if (bsti == -1)
            cout << "Impossible\n";
        else {
            cout << bstl << ":" << (bsti - bstl) << "\n";
            vector<pii> v; 
            while (bsti > 0) {
                auto p = pi[bsti][a][b][bstl];
                v.pb(p);
                a -= p.X;
                b -= p.Y;
                --bsti;
                bstl -= (p.X > p.Y);
            }
            reverse(ALL(v));
            for (int i = 0; i < SZ(v); i++)
                cout << v[i].X << ":" << v[i].Y << " \n"[i == SZ(v) - 1];
        }
            
    }

}