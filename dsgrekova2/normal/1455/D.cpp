#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int short
using namespace std;
void upd(int & a, int b, int p = 0){
    if(a == -1){
        a = b + p;
        return;
    }
    if(b != -1)
        a = min((long)a, (long)b + p);
}
void PolnalyubviTop(){
    int n, xx;
    cin >> n >> xx;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<bool>> sorted(n, vector<bool>(n, 0));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(501, vector<int>(501, -1)));
    vector<vector<vector<int>>> num(n + 1, vector<vector<int>>(501, vector<int>(501, -1)));
    dp[0][xx][a[0]] = 0;
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x <= 500; ++x){
            for (int j = 0; j <= 500; ++j) {
                if(dp[i][x][j] == -1)
                    continue;
                //cout << "KRYA " << num[i][x][j] << ' ' <<  dp[i][x][j] << ' ' << i << ' ' << x << ' ' << j << endl;
                if(i == n - 1)
                    continue;
                if(x < j and num[i][x][j] <= x) {
                    upd(dp[i][j][x], dp[i][x][j], 1);
                    num[i][j][x] = num[i][x][j];
                }
                if(j <= a[i + 1]) {
                    upd(dp[i + 1][x][a[i + 1]], dp[i][x][j]);
                    num[i + 1][x][a[i + 1]] = max(num[i][x][j], j);
                }
            }
        }
    }
    int res = -1;
    for (int k = 0; k < 501; ++k) {
        for (int j = 0; j < 501; ++j) {
            upd(res, dp[n-1][k][j]);
            //if(dp[n-1][k][j] != -1)
            //cout << dp[n-1][k][j] << ' ' << k << ' ' << j << ' ' << dp[n-1][k][j] << endl;
        }
    }
    cout << res << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}