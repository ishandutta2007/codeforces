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
int a[500005],b[500005];
int cnt[500005],fst[500005],lst[500005],nxt[500005],now[500005];
int dp[500005],dp2[500005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,x=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) cnt[a[i]]++,lst[a[i]]=i;
        for(int i=n;i>=1;i--) fst[a[i]]=i;
        for(int i=n;i>=1;i--) now[i]=now[nxt[a[i]]]+1,nxt[a[i]]=i;
        for(int i=n;i>=1;i--){
            dp[i]=dp[i+1];
            if(i==fst[a[i]]) dp[i]=max(dp[i],cnt[a[i]]+dp[lst[a[i]]+1]);
            else dp[i]=max(dp[i],now[i]);
        }
        cout<<n-dp[1]<<endl;
    }
    return 0;
}