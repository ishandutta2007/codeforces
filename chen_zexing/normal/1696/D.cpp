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
#include <random>
using namespace std;
int a[250005];
int dp[250005];
int mn[250005][20],mx[250005][20];
pair<int,int> query(int l,int r){
    int len=(r-l+1),p=log2(len);
    return make_pair(max(mx[l][p],mx[r-(1<<p)+1][p]),min(mn[l][p],mn[r-(1<<p)+1][p]));
}
int stk1[250005],stk2[250005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mn[i][0]=mx[i][0]=a[i];
        for(int i=1;i<=19;i++)
            for(int j=1;j<=n;j++){
                mx[j][i]=max(mx[j][i-1],mx[min(j+(1<<(i-1)),n)][i-1]);
                mn[j][i]=min(mn[j][i-1],mn[min(j+(1<<(i-1)),n)][i-1]);
            }
        int h1=0,h2=0;
        stk1[++h1]=stk2[++h2]=1;
        for(int i=2;i<=n;i++){
            dp[i]=n;
            while(h1&&a[stk1[h1]]<a[i]) h1--;
            while(h1>1&&query(stk1[h1-1],i).second==a[i]) h1--;
            if(h1&&query(stk1[h1],i).second==a[i]) dp[i]=min(dp[i],dp[stk1[h1]]+1);
            //cout<<i<<" "<<stk1[h1]<<" "<<dp[i]<<endl;
            stk1[++h1]=i;
            while(h2&&a[stk2[h2]]>a[i]) h2--;
            while(h2>1&&query(stk2[h2-1],i).first==a[i]) h2--;
            if(h2&&query(stk2[h2],i).first==a[i]) dp[i]=min(dp[i],dp[stk2[h2]]+1);
            //cout<<i<<" "<<stk2[h2]<<" "<<dp[i]<<endl;
            stk2[++h2]=i;
            //cout<<i<<" "<<h1<<" "<<h2<<" "<<dp[i]<<endl;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
//cf