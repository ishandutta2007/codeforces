#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
long long kk = 1000000007, dp[4001][4000], dp1[4000], n, ans = 1;
string s;
int main() {
    dp[0][0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0) {dp[i][j] = 1; continue;}
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % kk;
        }
    dp1[1] = 1;
    if (n > 1)
        ans = (ans + dp[n][1]) % kk;
    for (int i = 2; i < n; i++) {
        for (ll j = i; j > 0; j--) {
            dp1[j] = (dp1[j] * j + dp1[j - 1]) % kk;;
            ans = (ans + dp1[j] * dp[n][i]) % kk;
        }
    }
    cout << ans;
    re 0;
}