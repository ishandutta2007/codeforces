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
int a[1005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        long long ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i+=2) {
            long long now=a[i],lim=a[i]-1;
            for (int j=i+1;j<=n;j++){
                if(now<0) break;
                if(j%2) now+=a[j];
                else{
                    if(now-a[j]<=lim) ans+=lim-(max(0LL,now-a[j]))+1;
                    now-=a[j],lim=min(lim,now);
                }
                //cout<<ans<<" "<<now<<" "<<j<<endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//