
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;
 
int dp[200005][4][4];
 
// dp[i][a][b] = first two a, current two b
 
int n;
int ar[200005];
 
int dfs(int i, int a1, int a2, int b1, int b2) {
    if(i == 1) {
        if(a1 != b1 || a2 != b2) return 1000000;
        return (int)(ar[0] != a1) + (int)(ar[1] != a2);
    }
    int& loc = dp[i][a1*2+a2][b1*2+b2];
    if(loc != -1) return loc;
    int ans = ar[i] != b2;
    if(b1 == b2) ans += dfs(i-1, a1, a2, 1-b1, b1);
    else ans += min(dfs(i-1, a1, a2, 0, b1), dfs(i-1, a1, a2, 1, b1));
    return loc = ans;
}
 
int get(int a1, int a2, int b1, int b2) {
    return min(dfs(n-1, a1, a2, b1, b2), dfs(n-1, 1-a1, 1-a2, 1-b1, 1-b2));
}
 
int solve(string s) {
    rep(i, n) ar[i] = (s[i] == 'L');
    rep(i, n+2) rep(a, 4) rep(b, 4) dp[i][a][b] = -1;
    int v1 = get( 0, 0, 0, 1);
    int v2 = get(0, 0, 1, 1);
    int v3 = get(0, 1, 0, 1);
    int v4 = get(0, 1, 1, 0);
    int v5 = get(0, 1, 1, 1);
    return min(v1,min(v2,min(v3,min(v4,v5))));
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}