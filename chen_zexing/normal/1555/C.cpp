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
int a[3][100005];
int pre[100005],suf[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        int ans=INT_MAX;
        for(int i=1;i<=n;i++) scanf("%d",&a[1][i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[2][i]);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[2][i];
        suf[n+1]=0;
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[1][i];
        for(int i=1;i<=n;i++) ans=min(ans,max(pre[i-1],suf[i+1]));
        printf("%d\n",ans);
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