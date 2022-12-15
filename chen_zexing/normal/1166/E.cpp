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
#include <functional>
#define hash hassh
using namespace std;
int cnt[55][10005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int m,n,f=1;
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            int k,t;
            scanf("%d",&k);
            for(int j=1;j<=k;j++) scanf("%d",&t),cnt[i][t]=1;
        }
        for(int i=1;i<=m;i++)
            for(int j=i+1;j<=m;j++){
                int fl=0;
                for(int k=1;k<=n;k++) if(cnt[i][k]&&cnt[j][k]) fl=1;
                f&=fl;
            }
        puts(f?"possible":"impossible");
    }
    return 0;
}
//
/// 
//01
//