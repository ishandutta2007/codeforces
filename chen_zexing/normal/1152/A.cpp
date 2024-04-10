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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int cnta[2],cntb[2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1,t;i<=n;i++) scanf("%d",&t),cnta[t%2]++;
        for(int i=1,t;i<=m;i++) scanf("%d",&t),cntb[1-t%2]++;
        printf("%d\n",min(cnta[0],cntb[0])+min(cnta[1],cntb[1]));
    }
    return 0;
}
//
/// 
//01
//