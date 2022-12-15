#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int dp[200005],a[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) dp[i]=0,scanf("%d",&a[i]);
        dp[0]=1;
        map <int,int> mp;
        mp[a[1]+1]=1;
        for(int i=1;i<=n;i++){
            if(i>a[i]) dp[i]|=dp[i-a[i]-1];
            dp[i]|=mp[i];
            if(dp[i]&&i<n) mp[a[i+1]+i+1]=1;
        }
        puts(dp[n]?"YES":"NO");
    }
    return 0;
}