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
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0,now=1;
        while(now<=1e9) ans+=r/now-l/now,now*=10;
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