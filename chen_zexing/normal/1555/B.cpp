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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int w,h,x1,y1,x2,y2,x,y;
        scanf("%d%d%d%d%d%d",&w,&h,&x1,&y1,&x2,&y2);
        scanf("%d%d",&x,&y);
        if(x2-x1+x>w&&y2-y1+y>h){
            puts("-1");
            continue;
        }
        double ans=1e9;
        if(x2-x1+x<=w) ans=min(ans,min(double(max(0,x-x1)),double(max(0,x-(w-x2)))));
        if(y2-y1+y<=h) ans=min(ans,min(double(max(0,y-y1)),double(max(0,y-(h-y2)))));
        printf("%.8lf\n",ans);
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