#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005];
int cnt[35];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<30;i++)
            for(int j=1;j<=n;j++)
                if(a[j]&(1<<i))
                    cnt[i]++;
        int t=0;
        for(int i=0;i<30;i++)
            if(cnt[i]==n)
                t+=(1<<i);
        int c=0;
        for(int i=1;i<=n;i++) if(t==a[i]) c++;
        if(c<2) puts("0");
        else{
            long long mod=1000000007,ans=1;
            ans=1LL*c*(c-1)%mod;
            for(int i=1;i<=n-2;i++) ans=ans*i%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp