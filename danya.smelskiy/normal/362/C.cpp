#include <bits/stdc++.h>
using namespace std;

int n;
int f;
int dp[5005][5005];
int a[5005];
int res=1e9,kol;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    for (int j=1;j<=n;++j) {
        dp[i][j] = dp[i][j-1] + (a[j]<i ? 1 : 0 );
    }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
    if (a[j]<a[i]) {
        ++f;
        int now=dp[a[i]][i]+dp[a[j]][j]-dp[a[i]][j]-dp[a[j]][i];
        if (now<res) {
            res=now;
            kol=1;
        } else if (now==res) ++kol;
    }
    cout<<f+res+res+1<<" "<<kol;
}