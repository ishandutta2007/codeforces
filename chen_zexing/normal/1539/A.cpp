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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long n,x,t;
        scanf("%lld%lld%lld",&n,&x,&t);
        long long cnt=t/x,ans=0;
        if(n-1>=cnt){
            ans+=cnt*(cnt+1)/2;
            ans+=(n-1-cnt)*cnt;
            printf("%lld\n",ans);
        }
        else printf("%lld\n",n*(n-1)/2);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp