#include <bits/stdc++.h>
using namespace std;


int n,b,c;
int a[1000001];
vector<int> q;
long long dp[1000001][3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>b>>c;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int x=a[1];
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    x=a[n];
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    x=a[n]-1;
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    x=a[n]+1;
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    x=a[1]-1;
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    x=a[1]+1;
    for (int i=2;i<=sqrt(x);++i) {
        if (x%i!=0) continue;
        q.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) q.push_back(x);
    long long ans=1e18;
    for (int i=0;i<q.size();++i) {
        int x=q[i];
        for (int i=1;i<=n;++i) {
            dp[i][0]=1e18;
            dp[i][1]=1e18;
            dp[i][2]=1e18;
            if (a[i]%x==0) dp[i][0]=dp[i-1][0];
            if ((a[i]+1)%x==0 && dp[i-1][0]!=1e18) dp[i][0]=min(dp[i][0],dp[i-1][0]+c);
            if ((a[i]-1)%x==0 && dp[i-1][0]!=1e18) dp[i][0]=min(dp[i][0],dp[i-1][0]+c);

            if (dp[i-1][0]!=1e18) dp[i][1]=dp[i-1][0]+b;
            dp[i][1]=min(dp[i][1],dp[i-1][1]+b);

                if (a[i]%x==0) dp[i][2]=dp[i-1][2];
            if ((a[i]+1)%x==0) dp[i][2]=min(dp[i][2],dp[i-1][2]+c);
            if ((a[i]-1)%x==0) dp[i][2]=min(dp[i][2],dp[i-1][2]+c);
            dp[i][2]=min(dp[i][2],dp[i][1]);
        }
        ans=min(ans,dp[n][0]);
        ans=min(ans,dp[n][1]);
        ans=min(ans,dp[n][2]);
    }
    cout<<ans;
}