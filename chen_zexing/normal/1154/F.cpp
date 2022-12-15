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
int a[200005],pre[200005];
int cost[2005],x[200005],y[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        for(int i=1;i<=k;i++) cost[i]=pre[i];
        for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=k;i++)
            for(int j=1;j<=m;j++)
                if(x[j]<=i) cost[i]=min(cost[i],cost[i-x[j]]+pre[i]-pre[i-x[j]+y[j]]);
        printf("%d\n",cost[k]);
    }
    return 0;
}
//
/// 
//01
//