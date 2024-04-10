#include <bits/stdc++.h>
using namespace std;


int n,t;
int x,y;
vector<int> v[5005];
int dp[5005][5005];

inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        v[t-x].push_back(y);
    }
    for (int i=0;i<=t;++i)
        for (int j=0;j<=n;++j)
        dp[i][j]=-1e9;
    dp[0][1]=0;
    for (int i=0;i<=t;++i)
        sort(v[i].begin(),v[i].end(),cmp);
    int ans=0;
    for (int i=0;i<=t;++i) {
        ans=max(ans,dp[i][0]);
        for (int j=1;j<=n;++j) if (dp[i][j]>-1e9) {
            ans=max(ans,dp[i][j]);
            int sum=0;
            for (int k=0;k<=v[i].size() && k<=j;++k) {
                int kol=min(n,(j-k)*2);
                dp[i+1][kol]=max(dp[i+1][kol],dp[i][j]+sum);
                if (k<v[i].size()) sum+=v[i][k];
            }
        }
    }
    cout<<ans;
}