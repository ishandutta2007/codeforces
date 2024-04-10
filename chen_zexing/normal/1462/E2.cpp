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
long long mod=1000000007;
long long multi[200005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    multi[0]=1;
    for(int i=1;i<=200000;i++) multi[i]=multi[i-1]*i%mod;
    int T;
    cin>>T;
    while(T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n<=m-1){
            puts("0");
            continue;
        }
        sort(a+1,a+n+1);
        int l=1,r=m;
        long long ans=0;
        while(l<=n-m+1){
            while(r<=n&&a[r]-a[l]<=k) r++;
            r--;
            if(r-l<m-1){
                l++;
                continue;
            }
            ans+=multi[r-l]*qpow(multi[m-1],mod-2)%mod*qpow(multi[r-l-m+1],mod-2)%mod,ans%=mod;
            l++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}