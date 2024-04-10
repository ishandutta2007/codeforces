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
long long a[200005],h,tot,mn,pre[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>h>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),pre[i]=pre[i-1]+a[i],mn=min(mn,pre[i]);
        tot=pre[n];
        if(mn+h<=0){
            for(int i=1;i<=n;i++) if(pre[i]+h<=0){
                    printf("%d\n",i);
                    exit(0);
                }
        }
        else{
            if(tot>=0) puts("-1");
            else{
                long long d=h+mn,c=-tot;
                long long cnt=d/c+(d%c>0),ans=cnt*n;
                h+=cnt*tot;
                for(int i=1;i<=n;i++) if(pre[i]+h<=0){
                        printf("%lld\n",ans+i);
                        exit(0);
                    }
            }
        }
    }
    return 0;
}
//
/// 
//01
//