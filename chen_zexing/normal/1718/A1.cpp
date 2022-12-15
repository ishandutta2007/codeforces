#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],dp[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
        map <int,int> mp;
        mp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(mp.find(a[i])!=mp.end()) dp[i]=max(dp[i],dp[mp[a[i]]]+1);
            mp[a[i]]=i;
        }
        printf("%d\n",n-dp[n]);
    }
    return 0;
}