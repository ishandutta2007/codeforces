#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[105],mx[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++) mx[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx[i%k]=max(mx[i%k],a[i]);
        long long ans=0;
        for(int i=0;i<k;i++) ans+=mx[i];
        printf("%lld\n",ans);
    }
    return 0;
}