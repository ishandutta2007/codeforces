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
int cnta[200005],cntb[200005],a[200005],b[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnta[i]=cntb[i]=0;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),cnta[a[i]]++,cntb[b[i]]++;
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=1LL*(cnta[a[i]]-1)*(cntb[b[i]]-1);
        printf("%lld\n",1LL*n*(n-1)*(n-2)/6-ans);
    }
    return 0;
}
//
/// 
//01
//