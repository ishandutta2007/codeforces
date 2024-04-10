#include <bits/stdc++.h>
using namespace std;



int n;
string s;
int dp[105][2];


inline bool check(int x) {
    if (x&1) return false;
    int l=1;
    int r=(x/2)+1;
    while (r<=x) {
        if (s[l]!=s[r]) return false;
        ++l; ++r;
    }
    return true;
}

int main() {
    cin>>n;
    cin>>s;
    s="#"+s;
    for (int i=1;i<=n;++i) {
        dp[i][0]=dp[i][1]=1e9;
        dp[i][0]=dp[i-1][0]+1;
        dp[i][1]=dp[i-1][1]+1;
        if (check(i)) dp[i][1]=min(dp[i][1],dp[i/2][0]+1);
    }
    cout<<min(dp[n][0],dp[n][1]);
}