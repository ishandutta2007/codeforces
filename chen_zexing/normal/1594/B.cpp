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
long long mod=1e9+7;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans=0,temp=1;
        while(k){
            if(k%2) ans+=temp,ans%=mod;
            k>>=1;
            temp=temp*n%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//