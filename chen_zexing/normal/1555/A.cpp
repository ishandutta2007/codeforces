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
int dp[125];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long n;
        scanf("%lld",&n);
        long long ans=0;
        if(n<=6) ans+=15;
        else ans+=(n+1)/2*5;
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
//!