#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,ans;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans=a[n]-a[1];
        for(int i=2;i<=n;i++) ans=max(ans,a[i]-a[1]);
        for(int i=1;i<n;i++) ans=max(ans,a[n]-a[i]);
        for(int i=1;i<=n;i++){
            int nxt=i+n-1;
            if(nxt>n) nxt-=n;
            ans=max(ans,a[nxt]-a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}