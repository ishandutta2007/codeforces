#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[105];
char t[15][15];
int l[15],dp[105],pre[105],can[105],c[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++) scanf("%s",t[i]+1),l[i]=strlen(t[i]+1);
        dp[0]=1;
        for(int i=1;i<=n;i++) can[i]=0,dp[i]=INT_MAX/10;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                if(l[j]<=i){
                    int f=1;
                    for(int k=i-l[j]+1;k<=i;k++) if(t[j][k-(i-l[j])]!=s[k]) f=0;
                    if(f){
                        can[i]=max(can[i],l[j]);
                        if(can[i]==l[j]) c[i]=j;
                    }
                }
            for(int j=0;j<i;j++)
                if(j+can[i]>=i){
                    if(dp[j]+1<dp[i]) dp[i]=dp[j]+1,pre[i]=j;
                }
        }
        if(dp[n]==INT_MAX/10) puts("-1");
        else{
            int now=n;
            vector <int> v;
            while(now) v.push_back(now),now=pre[now];
            printf("%d\n",v.size());
            for(auto t:v)
                printf("%d %d\n",c[t],t-can[t]+1);
        }
    }
    return 0;
}