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
int dp[6];
int a[500005],to[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        to[4]=0,to[8]=1,to[15]=2,to[16]=3,to[23]=4,to[42]=5;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=to[a[i]];
        for(int i=1;i<=n;i++){
            if(a[i]==0) dp[a[i]]++;
            else if(dp[a[i]-1]>dp[a[i]]) dp[a[i]]++;
        }
        printf("%d\n",n-dp[5]*6);
    }
    return 0;
}
//
/// 
//01
//