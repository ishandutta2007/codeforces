#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long cal(int x){
    return 1LL*x*(x+1)/2;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m,cnt=0;
        cin>>n>>m;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) ans+=cal(i-1),cnt++;
            if(a[i]!=a[i+1]) ans+=cal(n-i);
        }
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            if(a[x]!=a[x-1]) ans-=cal(x-1),cnt--,ans-=cal(n-x+1);
            if(a[x]!=a[x+1]) ans-=cal(n-x),cnt--,ans-=cal(x);
            a[x]=y;
            if(a[x]!=a[x-1]) ans+=cal(x-1),cnt++,ans+=cal(n-x+1);
            if(a[x]!=a[x+1]) ans+=cal(n-x),cnt++,ans+=cal(x);
            printf("%lld\n",1LL*n*(n+1)/2*cnt-ans);
        }
    }
    return 0;
}