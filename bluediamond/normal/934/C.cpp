#include <bits/stdc++.h>

using namespace std;

const int N=2000+5;
int n,v[N];
int a1[N];
int a2[N];
int dp21[N][N];
int dp[N];

int ap(int x,int st,int dr) {
    if(st>dr) return 0;
    if(x==1) return a1[dr]-a1[st-1];
    else
        return a2[dr]-a2[st-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]==1)
            a1[i]=1;
        else
            a2[i]=1;
        a1[i]+=a1[i-1];
        a2[i]+=a2[i-1];
    }
    for(int st=1;st<=n;st++) {
        for(int dr=st;dr<=n;dr++) {
            if(v[dr]==2)
                dp21[st][dr]=dp21[st][dr-1];
            else {
                dp21[st][dr]=max(ap(2,st,dr),dp21[st][dr-1])+1;
            }
        }
    }
    int ans=0;
    for(int st=1;st<=n;st++) {
        for(int dr=st;dr<=n;dr++) {
            ans=max(ans,ap(1,1,st-1)+dp21[st][dr]+ap(2,dr+1,n));
        }
    }
    for(int i=1;i<=n;i++) {
        if(v[i]==1)
            dp[i]=dp[i-1];
        else {
            dp[i]=max(dp[i-1],ap(1,1,i))+1;
        }
    }
    ans=max(ans,dp[n]);
    cout<<ans<<"\n";
    return 0;
}
/**
**/