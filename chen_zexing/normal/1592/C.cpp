#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
vector <int> v[100005];
int a[100005],n,dp[100005],f[100005],s,fl=0;
void dfs(int x,int from){
    dp[x]=a[x];
    int cnt=0;
    for(auto t:v[x]) if(t!=from) dfs(t,x),dp[x]^=dp[t],f[x]|=f[t],cnt+=f[t];
    if(cnt>1) fl=1;
    if(dp[x]==0&&f[x]) fl=1;
    if(dp[x]==s) f[x]=1;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int k;
        s=fl=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) v[i].clear(),scanf("%d",&a[i]),s^=a[i],f[i]=dp[i]=0;
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y),v[y].push_back(x);
        }
        if(s==0) puts("YES");
        else if(k>=3){
            dfs(1,0);
            puts(fl?"YES":"NO");
        }
        else puts("NO");
    }
    return 0;
}
//
/// 
//01
//