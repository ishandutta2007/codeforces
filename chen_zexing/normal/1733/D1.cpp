#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char a[5005],b[5005];
long long dp[5005][2],pre[5005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        long long x,y;
        scanf("%d%lld%lld",&n,&x,&y);
        swap(x,y);
        scanf("%s",a+1),scanf("%s",b+1);
        vector <int> v;
        for(int i=1;i<=n;i++) if(a[i]!=b[i]) v.push_back(i);
        if(v.size()%2){
            puts("-1");
            continue;
        }
        if(v.size()==0){
            puts("0");
            continue;
        }
        if(x<=y){
            if(v.size()==2){
                if(v[0]==v[1]-1) printf("%lld\n",min(x*2,y));
                else printf("%lld\n",x);
            }
            else printf("%lld\n",x*int((v.size()/2)));
        }
        else{
            v.insert(v.begin(),0);
            dp[0][0]=0,dp[0][1]=LLONG_MAX/10;
            for(int i=1;i<v.size();i++){
                dp[i][0]=dp[i][1]=LLONG_MAX/10;
                dp[i][1]=min(dp[i-1][0],dp[i][1]);
                dp[i][0]=min(dp[i][0],dp[i-1][1]+x);
                if(i>1) dp[i][0]=min(dp[i][0],dp[i-2][0]+(v[i]-v[i-1])*y);
                if(i>1) dp[i][1]=min(dp[i][1],dp[i-2][1]+(v[i]-v[i-1])*y);
            }
            printf("%lld\n",dp[v.size()-1][0]);
        }
    }
    return 0;
}