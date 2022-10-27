#include<bits/stdc++.h>
using namespace std;
int a[100100],dp[100100];
int main(){
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        map<int,int>mp,last,same;
        int now=(1<<30)+1;
        mp[now] = 1;
        for(i=1;i<=n;i++){
            now^=a[i];
            if(mp[now]) last[i]=mp[now];
            mp[now] = i+1;
            if(a[i]==a[i-1]) same[i] = same[i-1];
            else             same[i] = i;
        }
        for(i=1;i<=n;i++){
            dp[i] = dp[i-1]+1;
            if(last[i]){
                dp[i]= min(dp[i],dp[last[i]-1]+i-last[i]);
            }
            if(same[i]<i){
                if(a[i]==0) dp[i] = min(dp[i],dp[same[i]-1]);
                else        dp[i] = min(dp[i],dp[same[i]-1]+(i-same[i]+2)/2);
            }
        }
        cout<<dp[n]<<endl;
    }
}