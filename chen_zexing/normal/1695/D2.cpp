#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
vector <int> v[200005];
int dp[200005][2],cnt[200005];
void dfs(int x,int from){
    for(auto t:v[x]) if(t!=from) dfs(t,x);
    if(from){
        dp[x][0]=0;
        int mx=0;
        for(auto t:v[x]) if(t!=from) dp[x][0]+=dp[t][0],mx=max(mx,dp[t][0]-dp[t][1]);
        dp[x][0]-=mx,dp[x][1]=dp[x][0];
        if(dp[x][0]==0) dp[x][0]++;
    }
    else{
        int mx=0;
        dp[x][0]=0;
        for(auto t:v[x]) if(t!=from) dp[x][0]+=dp[t][0],mx=max(mx,dp[t][0]-dp[t][1]);
        dp[x][0]-=mx;
    }
    //cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear(),cnt[i]=0;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),cnt[x]++,cnt[y]++;
        int rt=0;
        for(int i=1;i<=n;i++) if(cnt[i]>=3) rt=i;
        if(rt==0){
            if(n==1) puts("0");
            else puts("1");
            continue;
        }
        dfs(rt,0);
        printf("%d\n",dp[rt][0]);
    }
    return 0;
}
//cf
//1->2->4->7->5
//1->6->8
//    ->9
//1->3->10