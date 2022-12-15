#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=3;i<=n;i++) ans=max(ans,a[i]-a[i-1]+a[i]-a[1]);
        for(int i=n-2;i;i--) ans=max(ans,a[i+1]-a[i]+a[n]-a[i]);
        printf("%d\n",ans);
    }
    return 0;
}