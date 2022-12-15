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
int a[15];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1,t;i<=n;i++) scanf("%d",&t),a[i]=pow(10,t);
        int f=n;
        for(int i=1;i<n;i++){
            int tot=0;
            for(int j=1;j<=i;j++) tot+=a[j+1]/a[j]-1;
            if(tot>k){
                f=i;
                break;
            }
        }
        long long ans=0,cnt=0;
        for(int i=1;i<f;i++) cnt+=a[i+1]/a[i]-1,ans+=(a[i+1]/a[i]-1)*a[i];
        ans+=1LL*(k+1-cnt)*a[f];
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//