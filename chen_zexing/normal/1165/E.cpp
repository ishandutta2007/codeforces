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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[200005],b[200005];
long long aa[200005];
long long mod=998244353;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),aa[i]=1LL*i*(n-i+1)*a[i];
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1);
        sort(aa+1,aa+n+1,greater<long long>());
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=aa[i]%mod*b[i]%mod,ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//