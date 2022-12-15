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
int cnt[3];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,t;i<=n;i++) scanf("%d",&t),cnt[t]++;
        if(!cnt[1]){
            for(int i=1;i<=cnt[2];i++) printf("%d ",2);
            puts("");
        }
        else if(!cnt[2]){
            for(int i=1;i<=cnt[1];i++) printf("%d ",1);
            puts("");
        }
        else{
            printf("%d %d ",2,1);
            for(int i=1;i<cnt[2];i++) printf("2 ");
            for(int i=1;i<cnt[1];i++) printf("1 ");
        }
    }
    return 0;
}
//
/// 
//01
//