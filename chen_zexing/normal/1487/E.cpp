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
int a[4][150005];
long long dp[4][150005];
map <long long,int> mp;
int id[150005];
bool cmp1(int a,int b){
    return dp[1][a]<dp[1][b];
}
bool cmp2(int a,int b){
    return dp[2][a]<dp[2][b];
}
bool cmp0(int a,int b){
    return dp[0][a]<dp[0][b];
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n[4];
        for(int i=0;i<4;i++) cin>>n[i];
        for(int i=0;i<4;i++)
            for(int j=1;j<=n[i];j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n[0];i++) dp[0][i]=a[0][i];
        for(int i=1;i<=n[0];i++) id[i]=i;
        sort(id+1,id+n[0]+1,cmp0);
        for(int t=1;t<=3;t++) {
            int m;
            cin >> m;
            mp.clear();
            for (int i = 1, x, y; i <= m; i++) {
                scanf("%d%d", &x, &y);
                mp[1LL * x * 150005 + y] = 1;
            }
            for (int i = 1; i <= n[t]; i++) dp[t][i] = INT_MAX;
            for (int i = 1; i <= n[t]; i++) {
                for (int j = 1; j <= n[t-1]; j++)
                    if (!mp[1LL * id[j] * 150005 + i]) {
                        dp[t][i] = dp[t-1][id[j]]+a[t][i];
                        break;
                    }
            }
            for(int i=1;i<=n[t];i++) id[i]=i;
            if(t==1) sort(id+1,id+n[t]+1,cmp1);
            else if(t==2) sort(id+1,id+n[t]+1,cmp2);
        }
        long long ans=INT_MAX;
        for(int i=1;i<=n[3];i++) ans=min(ans,dp[3][i]);
        if(ans==INT_MAX) puts("-1");
        else printf("%lld\n",ans);
    }
    return 0;
}