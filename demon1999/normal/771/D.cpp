#include <bits/stdc++.h>
 
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define tm tmmm
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll p = 239;
const int ma = 16 * 1024;
//
int n, dp[76][76][76][3];
vector<int> pos[3];
string s;

int main() {
    //iostream::sync_with_stdio(0);
    //freopen("a.in", "r", stdin);
    cin >> n;
    cin >> s;
    forn (i, n) {
        if (s[i] == 'V')
            pos[0].push_back(i);
        else
        if (s[i] == 'K')
            pos[1].push_back(i);
        else
            pos[2].push_back(i);
    }
    forn (i, sz(pos[0]) + 1) {
        forn (j, sz(pos[1]) + 1) {
            forn (k, sz(pos[2]) + 1) {
                if (i + j + k == 0) continue;
                int cnti = i - 1, cntj = j - 1, cntk = k - 1;
                forn (p, j) {
                    if (i && pos[1][p] < pos[0][i - 1])
                        cnti++;
                    if (k && pos[1][p] < pos[2][k - 1])
                        cntk++;
                }
                forn (p, i) {
                    if (j && pos[0][p] < pos[1][j - 1])
                        cntj++;
                    if (k && pos[0][p] < pos[2][k - 1])
                        cntk++;
                }
                forn (p, k) {
                    if (i && pos[2][p] < pos[0][i - 1])
                        cnti++;
                    if (j && pos[2][p] < pos[1][j - 1])
                        cntj++;
                }
                forn (q, 3)
                dp[i][j][k][q] = int(1e9);
                if (i) 
                    dp[i][j][k][0] = min(dp[i - 1][j][k][0], min(dp[i - 1][j][k][1], dp[i - 1][j][k][2])) + 
                    max(pos[0][i - 1] - cnti, 0);
                if (j)
                    dp[i][j][k][1] = min(dp[i][j - 1][k][1], dp[i][j - 1][k][2]) + 
                    max(pos[1][j - 1] - cntj, 0);
                if (k)
                    dp[i][j][k][2] = min(dp[i][j][k - 1][0], min(dp[i][j][k - 1][1], dp[i][j][k - 1][2])) + 
                    max(pos[2][k - 1] - cntk, 0);    
                //cout << i << " " << j << " " << k << " " << dp[i][j][k][0] <<  " " << dp[i][j][k][1] <<  " " << dp[i][j][k][2] <<  " " << "\n";
            }
        }
    }
    cout << min(min(dp[sz(pos[0])][sz(pos[1])][sz(pos[2])][0], dp[sz(pos[0])][sz(pos[1])][sz(pos[2])][1]),
                dp[sz(pos[0])][sz(pos[1])][sz(pos[2])][2]) << "\n";
}