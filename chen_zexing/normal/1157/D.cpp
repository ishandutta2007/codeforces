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
int check(int st,int k,int n){
    long long now=0;
    for(int i=1;i<=k;i++){
        now+=1LL*st*(1<<(i-1));
        if(now>=n) return 1;
    }
    return 0;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,l=0,r=1e9;
        cin>>n>>k;
        while(l<r) {
            int now=(l+r)/2+1;
            if (1LL * (now * 2 + k - 1) * k / 2 <= n) l=now;
            else r=now-1;
        }
        int now=l;
        if(!check(now,k,n)){
            puts("NO");
            continue;
        }
        puts("YES");
        int sum=(now*2+k-1)*k/2,rest=n-sum,up=0,lst=now;
        printf("%d ",now);
        for(int i=2;i<=k;i++){
            while(rest>=k-i+1&&(now+i+up)<=lst*2) rest-=k-i+1,up++;
            printf("%d ",now+i-1+up),lst=now+i-1+up;
        }
    }
    return 0;
}
//
/// 
//01
//