#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],pre[200005],suf[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,ans;
        scanf("%d",&n),ans=n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        for(int i=0;i<=n;i++){
            ans=min(ans,max(pre[i],(n-i)-(pre[n]-pre[i])));
        }
        printf("%d\n",ans);
    }
    return 0;
}