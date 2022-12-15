#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005],cnt[200005];
int dp[200005];
vector <int> v[200005];
int main() {
    for(int i=1;i<=200000;i++){
        for(int j=1;j*j<=i;j++)
            if(i%j==0){
                v[i].push_back(j);
                if(j*j!=i) v[i].push_back(i/j);
            }
    }
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=200000;i++) cnt[i]=0,dp[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        int ans=0;
        for(int i=1;i<=200000;i++){
            if(cnt[i]==0) continue;
            dp[i]=cnt[i];
            for(int j=0;j<v[i].size();j++)
                if(v[i][j]!=i)
                    dp[i]=max(dp[i],dp[v[i][j]]+cnt[i]);
            ans=max(ans,dp[i]);
        }
        //for(int i=1;i<=n;i++) cout<<dp[a[i]]<<" ";
        cout<<n-ans<<endl;
    }
    return 0;
}