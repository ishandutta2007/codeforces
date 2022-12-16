#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int mod = 1000000007;
const int NMAX = 1010;

int dp[NMAX][NMAX][2];

int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=n-1; i>=0; --i) {
        dp[i][0][0] = dp[i+1][0][1];
        dp[i][0][1] = dp[i+1][0][0]+1;
        for(int j=1; j<n-i; ++j) {
            dp[i][j][0] = dp[i][j-1][1]+dp[i+1][j][1];
            while(dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            dp[i][j][1] = dp[i][j][0] + dp[i][j-1][0]-dp[i][j-1][1]+1;
        }
        dp[i][n-i][0] = dp[i][n-i-1][1];
        dp[i][n-i][1] = dp[i][n-i-1][0]+1;
        for(int j=0; j<=n-i; ++j) {
            while(dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            while(dp[i][j][1] >= mod) dp[i][j][1] -= mod;
        }
    }
    cout << dp[0][n][1] << endl;
    return 0;
}