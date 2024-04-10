#include <bits/stdc++.h>
using namespace std;

int n,m;
long long v[100005];
long long c[100005];
long long dp[100005];
bool used[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>v[i];
    for (int i=1;i<=n;++i)
        cin>>c[i];
    for (int i=1;i<=m;++i) {
        long long x,y;
        cin>>x>>y;
        for (int i=0;i<=n;++i){
            dp[i]=-1e18;
            used[i]=false;
        }
        int q1=0,q2=0;
        long long ans=0;
        for (int i=1;i<=n;++i) {
            long long z=c[i];
            if (used[z]==false) dp[z]=y*v[i];
            else dp[z]=max(dp[z],dp[z]+v[i]*x);
            used[z]=true;
            dp[z]=max(dp[z],v[i]*y);
            if (q1 && q1!=z) dp[z]=max(dp[z],dp[q1]+v[i]*y);
            if (q2 && q2!=z) dp[z]=max(dp[z],dp[q2]+v[i]*y);
            if (dp[q2]>dp[q1]) swap(q1,q2);
            if (z==q1 || z==q2) continue;
            if (dp[q2]<dp[z]) {
                q2=z;
                if (dp[q1]<dp[q2]) swap(q1,q2);
            }
        }
        cout<<max(0ll,max(dp[q1],dp[q2]))<<'\n';
    }
}