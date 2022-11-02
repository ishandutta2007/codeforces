// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 150000 + 10
#define inf 0x3f3f3f3f

int t, n, dp[maxn][3][3], fr[maxn][3][3][2];

void U(int &now, int val, int j, int k, int newj, int newk, int i) {
    if (now > val) {
        now = val;
        fr[i + 1][newj][newk][0] = j;
        fr[i + 1][newj][newk][1] = k;
    }
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        string s, one = "one", two = "two";
        cin >> s;
        for (int i = 0; i <= s.size(); ++ i) {
            for (int j = 0; j < 3; ++ j) {
                for (int k = 0; k < 3; ++ k) {
                    dp[i][j][k] = inf;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int i = 0; i < s.size(); ++ i) {
            for (int j = 0; j < 3; ++ j) {
                for (int k = 0; k < 3; ++ k) {
                    int newj = j, newk = k;
                    if (s[i] == one[j]) newj ++;
                    else if (s[i] == one[0]) newj = 1;
                    else newj = 0;
                    if (s[i] == two[k]) newk ++;
                    else if (s[i] == two[0]) newk = 1;
                    else newk = 0;

                    if (newj < 3 && newk < 3) 
                        U(dp[i + 1][newj][newk], dp[i][j][k] + 0, j, k, newj, newk, i);
                    U(dp[i + 1][j][k], dp[i][j][k] + 1, j, k, j, k, i);
                }
            }
        }
//        for (int i = 0; i <= s.size(); ++ i) {
//            cout << "i = " << i << endl;
//            for (int j = 0; j < 3; ++ j) {
//                for (int k = 0; k < 3; ++ k) {
//                    cout << dp[i][j][k] << " ";
//                }
//            }
//            cout << endl;
//        }
//        return 0;
        int ans = dp[s.size()][0][0], j = 0, k = 0;
        for (int jj = 0; jj < 3; ++ jj) {
            for (int kk = 0; kk < 3; ++ kk) {
                if (dp[s.size()][jj][kk] < ans)
                    ans = dp[s.size()][jj][kk], j = jj, k = kk;
            }
        }
//        cout << "final" << j << " " << k << endl;
        cout << ans << "\n";
        vector<int> sol;
        for (int i = s.size(); i > 0; -- i) {
            if (dp[i - 1][j][k] + 1 == dp[i][j][k])
                sol.emplace_back(i);
            else {
                int prej = fr[i][j][k][0];
                int prek = fr[i][j][k][1];
                j = prej, k = prek;
            }
        }
        for (int i = 0; i < sol.size(); ++ i) cout << sol[i] << " \n"[i + 1 == sol.size()];
        if (sol.size() == 0) cout << "\n";
    
    }
    return 0;
}