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
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans=max(ans,1LL*a[i]*a[i-1]);
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//
/*
 XO#
 #XO
 XXO
 OX#
 */