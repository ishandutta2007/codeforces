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
int dp[100005];
char s[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,p,k,x,y,ans=INT_MAX;
        cin>>n>>p>>k;
        scanf("%s",s+1);
        cin>>x>>y;
        for(int i=n;i>=p;i--) {
            if(s[i]=='0') dp[i]=x;
            else dp[i]=0;
            if(i+k<=n) dp[i]+=dp[i+k];
            ans=min(ans,dp[i]+(i-p)*y);
        }
        cout<<ans<<endl;
    }
    return 0;
}