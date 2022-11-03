#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <ctime>

using namespace std;

int a[200005],n;
long long dp[200005];

long long solve(int x) {
    if (dp[x]!=-1) return dp[x];
    int st=x; dp[x]=-2;
    long long ret=0;
    ret+=a[x]; x-=a[x];
    if (x<=0||x>n) return dp[st]=ret;
    if (x==1||x==st) {
        return dp[st]=-2;
    }
    ret+=a[x]; x+=a[x];
    if (x<=0||x>n) return dp[st]=ret;
    if (x==1||x==st) {
        return dp[st]=-2;
    }
    long long val=solve(x);
    if (val==-2) return dp[st]=-2;
    return dp[st]=val+ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n;++i) {
        long long val=solve(1+i);
        if (val==-2) puts("-1");
        else printf("%I64d\n",val+i);
    }
    return 0;
}