#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
using namespace std;
long long x[200005],y[200005],cost[200005],pre[200005],s[200005],mod=998244353;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&s[i]);
        for(int i=1;i<=n;i++){
            if(i==1) cost[i]=x[i]-y[i];
            else{
                int id=lower_bound(x+1,x+n+1,y[i])-x;
                cost[i]=pre[i-1]-pre[id-1]+x[i]-y[i],cost[i]%=mod;
            }
            pre[i]=pre[i-1]+cost[i],pre[i]%=mod;
        }
        ans=x[n]+1;
        for(int i=1;i<=n;i++) if(s[i]) ans+=cost[i],ans%=mod;
        printf("%lld\n",(ans+mod)%mod);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//