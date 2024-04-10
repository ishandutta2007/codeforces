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
int a[200005];
long long mod=998244353;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,mx=0,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
        for(int i=1;i<=n;i++) if(a[i]==mx) cnt++;
        if(cnt>1){
            long long ans=1;
            for(int i=1;i<=n;i++) ans=ans*i%mod;
            printf("%lld\n",ans);
        }
        else{
            int c=0;
            for(int i=1;i<=n;i++) if(a[i]==mx-1) c++;
            if(!c){
                puts("0");
                continue;
            }
            long long ans=1,temp=1;
            for(int i=1;i<=n;i++) ans=ans*i%mod;
            for(int i=1;i<=c;i++) temp=temp*i%mod;
            for(int i=c+2;i<=n;i++) temp=temp*i%mod;
            printf("%lld\n",((ans-temp+mod)%mod+mod)%mod);
        }
    }
    return 0;
}
//
/// 
//01
//