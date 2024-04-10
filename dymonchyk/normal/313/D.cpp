#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int go[302][302];
long long dp[302][302];

void update(long long & res,long long val) {
    res=min(res,val);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int inf=2000000000;
    long long INF=1LL*inf*inf;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j) {
            go[i][j]=inf;
            dp[i][j]=1LL*inf*inf;
        }
    for(int i=0;i<m;++i) {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c); --l; --r;
        for(int j=l;j<=r;++j)
            go[j][r]=min(go[j][r],c);
    }
    dp[0][0]=0;
    for(int pos=0;pos<n;++pos) {
        for(int have=0;have<k;++have) {
            if (dp[pos][have]!=INF) {
                update(dp[pos+1][have],dp[pos][have]);
                for(int r=pos;r<n;++r) {
                    if (go[pos][r]!=inf)
                        update(dp[r+1][have+r-pos+1],dp[pos][have]+go[pos][r]);
                }
            }
        }
    }
    long long ans=INF;
    for(int i=0;i<=n;++i)
        for(int j=k;j<=n;++j)
            ans=min(ans,dp[i][j]);
    if (ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}