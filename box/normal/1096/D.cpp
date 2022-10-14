// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int n;
string s;
ll dp[100005][4];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    s = ' '+s;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0; 
    rep1(i, n) {
        ll v; cin >> v;
        if(s[i] == 'h') {
            dp[i][0] = dp[i-1][0] + v;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        } else if(s[i] == 'a') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + v;
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = dp[i-1][3];
        } else if(s[i] == 'r') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2] + v;
            dp[i][3] = min(dp[i-1][2], dp[i-1][3]);
        } else if(s[i] == 'd') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3] + v;
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
    }
    cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << endl;
}