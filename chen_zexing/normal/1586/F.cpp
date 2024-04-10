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
int ans[1005][1005],k;
void solve(int l,int r,int blk,int c){
    if(blk==0||l>=r) return;
    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            if((i-1)/blk!=(j-1)/blk)
                ans[i][j]=c;
    for(int i=l;i<=r;i+=blk) solve(i,min(r,i+blk-1),blk/k,c-1);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,c=1;
        cin>>n>>k;
        int now=k-1,blk=1;
        while(now<n-1) now=now*k+k-1,c++,blk*=k;
        printf("%d\n",c);
        solve(1,n,blk,c);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                printf("%d ",ans[i][j]);
    }
    return 0;
}
//
/// 
//01
//