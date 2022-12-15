#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        long long ans=0;
        int mx=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
            mx=max(mx,max(a[i],b[i]));
            ans+=a[i]+b[i];
            ans+=a[i]+b[i];
            ans-=max(a[i],b[i])*2;
        }
        printf("%lld\n",ans+mx*2);
    }
    return 0;
}