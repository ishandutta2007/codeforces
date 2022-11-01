#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,a[2005],dp[2005];

bool check(const int &w){
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(abs(a[j]-a[i])<=(long long)(i-j)*w)dp[i]=max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp+1,dp+1+n)>=n-k;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0,r=2e9,m,ans;
    while(l<=r){
        m=(unsigned)l+r>>1;
        if(check(m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}