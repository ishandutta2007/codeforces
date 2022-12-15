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
        long long n;
        scanf("%lld",&n);
        int ans=0;
        while(n) ans=max(ans,int(n%10)),n/=10;
        printf("%d\n",ans);
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