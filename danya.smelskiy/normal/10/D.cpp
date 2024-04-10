#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[505],b[505];
int dp[505][505],pred[505][505];
vector<int> q;
int ans,pos;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            dp[i][j]=dp[i][j-1];
            pred[i][j]=pred[i][j-1];
            if (a[i]==b[j]) {
                dp[i][j]=1;
                pred[i][j]=0;
                for (int k=i-1;k>=0;--k)
                if (a[k]<a[i] && dp[k][j-1]+1>dp[i][j]) {
                    dp[i][j]=dp[k][j-1]+1;
                    pred[i][j]=k;
                }
            }
        }
    }
    for (int i=1;i<=n;++i)
    if (dp[i][m]>ans) {
        ans=dp[i][m];
        pos=i;
    }
    int j=m;
    cout<<ans<<'\n';
    for (int i=1;i<=ans;++i) {
        q.push_back(a[pos]);
        while (b[j]!=a[pos]) --j;
        pos=pred[pos][j];
        --j;
    }
    for (int i=q.size()-1;i>=0;--i)
        cout<<q[i]<<" ";
}