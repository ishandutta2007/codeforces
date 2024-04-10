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
long long a[200005],pre[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        int m;
        cin>>m;
        for(int i=1;i<=m;i++){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            long long ans=LLONG_MAX;
            int pos=lower_bound(a+1,a+n+1,x)-a;
            if(pos!=n+1) ans=min(ans,max(0LL,y-(pre[n]-a[pos])));
            if(pos!=1) ans=min(ans,max(0LL,y-(pre[n]-a[pos-1]))+x-a[pos-1]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
//