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
long long a[200005],dp[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=n;i>=1;i--){
            if(i+a[i]>n) dp[i]=a[i];
            else dp[i]=dp[i+a[i]]+a[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}