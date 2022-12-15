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
        long long s,n,k;
        scanf("%lld%lld%lld",&s,&n,&k);
        if(k>s) puts("NO");
        else{
            long long len=k*2,tot=s,have=n;
            long long nd=have/k*len+have%k;
            if(nd>tot||k==s) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
//
/// 
//01
//