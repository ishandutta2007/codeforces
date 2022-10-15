#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,d;
    cin>>n>>d;
    string a;
    cin>>a;
    a="x"+a;
    vector<int>dp(n+5);
    dp[1]=0;
    for(int i=2;i<=n;i++) {
        if(a[i]=='0') {dp[i]=-1; continue;}
        int mi=(1<<30);
        for(int j=i-1;j>=1 && i-j<=d;j--) {
            if(dp[j]==-1) continue;
            mi=min(mi,dp[j]);
        }
        if(mi==(1<<30)) dp[i]=-1;
        else {
            dp[i]=mi+1;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}