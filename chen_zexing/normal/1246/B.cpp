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
int a[100005],b[100005],cnt[100005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k==2) {
            for (int i = 1; i <= n; i++) {
                b[i]=a[i];
                for (int j=2;j*j<=b[i];j++)
                    if(b[i]%j==0){
                        while(b[i]%(1LL*j*j)==0) b[i]/=j*j;
                    }
            }
            long long ans=0;
            for(int i=1;i<=n;i++) ans+=cnt[b[i]],cnt[b[i]]++;
            printf("%lld\n",ans);
        }
        else{
            for(int i=1;i<=n;i++) cnt[a[i]]++;
            long long ans=0;
            for(int i=1;1;i++){
                double tar=pow(i,k);
                if(tar>1e10) break;
                long long t=tar;
                for(int j=1;1LL*j*j<=t;j++)
                    if(t%j==0&&t/j<=1e5){
                        if(j==t/j) ans+=1LL*cnt[j]*(cnt[j]-1)/2;
                        else ans+=1LL*cnt[j]*cnt[t/j];
                    }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
//