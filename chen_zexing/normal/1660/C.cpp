#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
char s[200005];
int f[26],dp[200005][2],pre[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),ans=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++) pre[i]=0;
        for(int i=1;i<=n;i++) pre[i]=f[s[i]-'a'],f[s[i]-'a']=i;
        for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INT_MIN/2;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[pre[i]][1]+2;
            dp[i][1]=ans;
            //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans=max(ans,dp[i][0]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
//unordered_map