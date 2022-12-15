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
using namespace std;
int cnt[1000005],fac[1000005];
long long mod=998244353;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
                cnt[j]++;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*2%mod;
        long long ans=cnt[n];
        for(int i=1;i<n;i++) ans+=1LL*fac[n-i-1]*cnt[i]%mod,ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp