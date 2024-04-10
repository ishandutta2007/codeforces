#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],f[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,mn=INT_MAX,mx=0,fl=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=0;
        for(int i=1;i<n;i++) if(a[i]==a[i+1]) f[i]=f[i+1]=1,fl=1;
        if(!fl){
            puts("0");
            continue;
        }
        for(int i=1;i<=n;i++) if(f[i]) mn=min(mn,i),mx=max(mx,i);
        if(mx-mn>=2) printf("%d\n",max(mx-mn-2,1));
        else puts("0");
    }
    return 0;
}