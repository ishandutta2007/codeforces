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
int MOD = 1000000007;

int dp[505][505];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, b; cin >> n >> m >> b >> MOD;
    m++; b++;
    dp[0][0] = 1%MOD;
    rep1(i, n) {
        int a; cin >> a;
        rep(L, m) rep(B, b) {
            if(L && a <= B) dp[L][B] = (dp[L][B] + dp[L-1][B-a]) % MOD; 
        }
    }
    int ans = 0;
    rep(B, b) ans = (ans + dp[m-1][B]) % MOD;
    cout << ans << endl;
}