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
int a[305];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,mx=0,mn=INT_MAX,f=1;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),mn=min(mn,a[i]);
        long long tar=1LL*mx*mn;
        for(int i=1;i<=n;i++) if(tar%a[i]) f=0;
        if(!f){
            puts("-1");
            continue;
        }
        int now=1;
        long long t=tar;
        for(int i=2;1LL*i*i<=tar;i++)
            if(tar%i==0){
                int c=1;
                while(tar%i==0) tar/=i,c++;
                now*=c;
            }
        if(tar>1) now*=2;
        if(now==n+2) printf("%lld\n",t);
        else puts("-1");
    }
    return 0;
}
//
/// 
//01
//