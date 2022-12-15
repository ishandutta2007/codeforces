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
using namespace std;
long long mod=1000000007;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long n;
        scanf("%lld",&n);
        long long now=1,cnt=0,ans=0;
        for(int i=2;now<=n;i++){
            now=now*i/gcd(now,i);
            long long c=n/now*(now-1)+n%now;
            ans+=(c-cnt)*i%mod,ans%=mod;
            cnt=c;
        }
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