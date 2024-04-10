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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n>m){
            puts("0");
            continue;
        }
        int f=0,tar=0,mn=-1;
        for(int i=30;i>=0;i--){
            int t1=((n&(1<<i))>0),t2=((m&(1<<i))>0);
            if(t1&&!t2){
                f=1;
                printf("%d\n",tar);
                break;
            }
            if(t2&&!t1){
                tar^=(1<<i),n^=(1<<i);
            }
            if(!t1&&!t2) mn=tar+(1<<i);
        }
        if(!f) printf("%d\n",mn);
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