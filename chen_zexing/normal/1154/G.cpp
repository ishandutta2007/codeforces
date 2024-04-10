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
int a[1000005];
int fid[10000005],sid[10000005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!fid[a[i]]) fid[a[i]]=i;
            else if(!sid[a[i]]) sid[a[i]]=i;
        }
        long long mn=LLONG_MAX/10,id1=-1,id2=-1;
        for(int i=1;i<=1e7;i++){
            int p1=0,p2=0;
            for(int j=i;j<=1e7;j+=i){
                if(fid[j]){
                    if(!p1) p1=fid[j];
                    else if(!p2) p2=fid[j];
                }
                if(sid[j]){
                    if(!p1) p1=sid[j];
                    else if(!p2) p2=sid[j];
                }
                if(p1&&p2) break;
            }
            if(p1&&p2&&1LL*a[p1]*a[p2]/i<mn) mn=1LL*a[p1]*a[p2]/i,id1=p1,id2=p2;
        }
        if(id1>id2) swap(id1,id2);
        printf("%lld %lld\n",id1,id2);
    }
    return 0;
}
//
/// 
//01
//