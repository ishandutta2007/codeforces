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
long long d[200005],a[200005],cnt[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,f=1;
        long long mn=0;
        cin>>n;
        for(int i=1;i<n;i++) scanf("%lld",&d[i]);
        a[1]=0;
        for(int i=2;i<=n;i++) a[i]=a[i-1]+d[i-1],mn=min(mn,a[i]);
        long long up=1-mn;
        for(int i=1;i<=n;i++) a[i]+=up;
        for(int i=1;i<=n;i++){
            if(a[i]>n||a[i]<0) f=0;
            else if(cnt[a[i]]) f=0;
            else cnt[a[i]]++;
        }
        if(!f) puts("-1");
        else{
            for(int i=1;i<=n;i++) printf("%lld ",a[i]);
        }
    }
    return 0;
}
//
/// 
//01
//