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
int a[500005],pre[500005],suf[500005];
long long presum[500005],sufsum[500005];
int stk[500005],h,f[500005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            while(h&&a[stk[h]]>a[i]) h--;
            pre[i]=stk[h];
            stk[++h]=i;
            presum[i]=1LL*(i-pre[i])*a[i]+presum[pre[i]];
        }
        h=0;
        stk[0]=n+1;
        for(int i=n;i>=1;i--){
            while(h&&a[stk[h]]>a[i]) h--;
            suf[i]=stk[h];
            stk[++h]=i;
            sufsum[i]=1LL*(suf[i]-i)*a[i]+sufsum[suf[i]];
        }
        int p=-1;
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long temp=0;
            temp=1LL*(suf[i]-pre[i]-1)*a[i]+presum[pre[i]]+sufsum[suf[i]];
            if(temp>ans){
                ans=temp;
                p=i;
            }
        }
        f[p]=a[p];
        for(int i=p+1;i<=n;i++) f[i]=min(f[i-1],a[i]);
        for(int i=p-1;i;i--) f[i]=min(f[i+1],a[i]);
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
    }
    return 0;
}