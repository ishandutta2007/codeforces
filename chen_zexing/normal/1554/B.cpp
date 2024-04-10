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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long mx=LLONG_MIN;
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1&&1LL*(i-j-1)*j<=k*n;j--)
                mx=max(mx,1LL*i*j-1LL*k*(a[i]|a[j]));
        printf("%lld\n",mx);
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