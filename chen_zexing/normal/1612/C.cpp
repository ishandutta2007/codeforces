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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long k,x;
        scanf("%lld%lld",&k,&x);
        long long l=1,r=k*2-1;
        while(l<r){
            long long mid=(l+r)>>1;
            long long ans=0;
            if(mid<=k) ans=mid*(mid+1)/2;
            else{
                ans=k*(k+1)/2;
                long long tmid=mid-k;
                ans+=(k-1+k-tmid)*tmid/2;
            }
            if(ans<x) l=mid+1;
            else r=mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}
//
/// 
//01
//