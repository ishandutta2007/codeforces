//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define debug(x) cout << #x << " is " << x << endl
using namespace std;
#define MAXN 508
#define INF 20000100

int n, m, k;
int hor[MAXN][MAXN];
int ver[MAXN][MAXN];
int dp[MAXN][MAXN][12];

void find(int i, int j, int x) {
    int min_ans = INF;
    if(j!=0)
    {min_ans = min(min_ans, hor[i][j] + dp[i][j-1][x-1] );}
    if(j!=(m-1))
    {min_ans = min(min_ans, hor[i][j+1] + dp[i][j+1][x-1] );}
    if(i!=0)
    {min_ans = min(min_ans, ver[i][j] + dp[i-1][j][x-1] );}
    if(i!=(n-1))
    {min_ans = min(min_ans, ver[i+1][j] + dp[i+1][j][x-1] );}
    dp[i][j][x] = min_ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=m; j++) {
            if(j==0||j==m) {
                hor[i][j] = INF;
                continue;
            }
            cin >> hor[i][j];
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<=m; j++) {
    //         cout << hor[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0||i==n) {
                ver[i][j] = INF;
                continue;
            }
            cin >> ver[i][j];
        }
    }   
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << ver[i][j] << " ";
    //     }
    //     cout << endl;
    // }    

    if(k%2!=0) {
        forn(i, n) {
            forn(j, m) {
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    k /= 2;
    forn(a, k) {
        forn(i, n) {
            forn(j, m) {
                dp[i][j][a] = INF;
            }
        }
    } 
    forn(i, n) {
        forn(j, m) {
            dp[i][j][0] = 0;
        }
    }
    for(int x = 1; x<=k; x++) {
        forn(i, n) {
            forn(j, m) {
                find(i, j, x);
            }
        }
    }
    forn(i, n) {
        forn(j, m) {
            dp[i][j][k] *= 2;
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
    return 0;
}