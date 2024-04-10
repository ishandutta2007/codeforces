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
long long pre[200005],mx[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i],mx[i]=max(mx[i-1],pre[i]);
        for(int i=1;i<=m;i++){
            long long x;
            scanf("%lld",&x);
            if(x>mx[n]&&pre[n]<=0){
                printf("-1 ");
                continue;
            }
            long long ans=0;
            if(x>mx[n]){
                ans+=1LL*(x-mx[n])/pre[n]*n;
                x-=1LL*(x-mx[n])/pre[n]*pre[n];
            }
            while(x>mx[n]) ans+=n,x-=pre[n];
            int l=1,r=n;
            while(l<r){
                int mid=(l+r)>>1;
                if(mx[mid]<x) l=mid+1;
                else r=mid;
            }
            printf("%lld ",ans+l-1);
        }
        puts("");
    }
    return 0;
}