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
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if(k==1) printf("%lld\n",n-1);
        else{
            long long t=0,base=1;
            while(base<k){
                base*=2,t++;
            }
            printf("%lld\n",t+(n-base)/k+((n-base)%k>0));
        }
    }
    return 0;
}
//
/// 
//01
//