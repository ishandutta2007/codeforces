#include <bits/stdc++.h>

using namespace std;
//typedef long long int;
typedef pair<int, int> pii;

const int NMAX = 6000;
const int LLINF = 0x3f3f3f3f;

int n;
int c[NMAX], l[NMAX], nx[NMAX];
int dp[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    memset(dp, LLINF, sizeof dp);
    int lst = 0;
    int fst = 0;
    for(int i=1;i<=n;++i) {
        cin >> c[i];
        if(c[i] != lst) {
            l[i-1] = fst;
            for(int j=i-1;j>=fst;--j) {
                nx[j] = i-1;
            }
            //cerr << " dp " << fst << " " << i-1 << " = 0" << endl;
            dp[fst][i-1] = 0;
            //cerr << "   " << dp[fst][i-1] << endl;
            fst = i;
            lst = c[i];
        }
        l[i] = fst;
    }
    for(int j=n;j>=fst;--j) {
        nx[j] = n;
    }
    dp[fst][n] = 0;
    for(int d=0;d<n;++d) {
        for(int i=1;i+d<=n;++i) {
            int j = i+d;
            //cerr << " dp[" << i << " " << j << "] = " << dp[i][j] << " " << endl;
            int f = nx[j+1];
            int b = l[i-1];
            if(f != 0) {
                dp[i][f] = min(dp[i][f], dp[i][j]+1);
            }
            if(b != 0) {
                dp[b][j] = min(dp[b][j], dp[i][j]+1);
            }
            if(f != 0 && b != 0 && c[f] == c[b]) {
                dp[b][f] = min(dp[b][f], dp[i][j]+1);
                //cerr << " -- " << dp[b][f] << " at " << b << " " << f << endl;
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}