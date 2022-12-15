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
        int x,y;
        scanf("%d%d",&x,&y);
        if((x+y)%2) puts("-1 -1");
        else{
            if(x%2==0) printf("%d %d\n",x/2,y/2);
            else printf("%d %d\n",x/2,y/2+1);
        }
    }
    return 0;
}
//
/// 
//01
//