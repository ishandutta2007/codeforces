#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 202, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char s[MN], t[MN];
int dp[MN][MN][MN<<2];
struct State {
    int i,j,sum;
};
State from[MN][MN][MN<<2];
int solve (int i, int j, int sum) {
    if (sum > 800 || sum < 0) return INT_MAX>>1;
    if (i == 0 && j == 0 && sum == 0) return 0;
    if (i == 0 && j == 0) return sum;
    if (~dp[i][j][sum]) return dp[i][j][sum];
    int ret = INT_MAX>>1;
    int att1 = solve(i-(s[i]=='('),j-(t[j]=='('),sum-1)+1, att2 = solve(i-(s[i]==')'),j-(t[j]==')'),sum+1)+1;
    if (att1 < ret){
        ret = att1;
        from[i][j][sum] = {i-(s[i]=='('),j-(t[j]=='('),sum-1};
    }
    if (att2 < ret) {
        ret = att2;
        from[i][j][sum] = {i-(s[i]==')'),j-(t[j]==')'),sum+1};
    }
    return dp[i][j][sum] = ret;
}
int main() {
    memset(dp,-1,sizeof dp);
    scanf ("%s",s+1);
    scanf ("%s",t+1);
    int n = strlen(s+1); int m = strlen(t+1);
    solve(n,m,0);
    State cur = {n,m,0}; string ret;
    while (cur.i != 0 || cur.j != 0) {
        State old = from[cur.i][cur.j][cur.sum];
        if (old.sum > cur.sum) ret += ')';
        else ret += '(';
        cur = old;
    }
    while (cur.sum != 0) ret += '(', --cur.sum;
    reverse(all(ret));
    printf ("%s\n",ret.c_str());
    return 0;
}