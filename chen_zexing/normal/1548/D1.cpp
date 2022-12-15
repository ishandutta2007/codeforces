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
int x[6005],y[6005];
long long cnt[2][2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),x[i]/=2,y[i]/=2,cnt[x[i]%2][y[i]%2]++;
        long long ans=0;
        ans=cnt[0][0]*cnt[0][1]*cnt[1][0]+cnt[0][0]*cnt[0][1]*cnt[1][1]+cnt[0][0]*cnt[1][0]*cnt[1][1]+cnt[0][1]*cnt[1][0]*cnt[1][1];
        printf("%lld\n",1LL*n*(n-1)*(n-2)/6-ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!