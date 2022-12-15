#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        int mx=0,mn=INT_MAX,cmx=0,cmn=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]==mx) cmx++;
            if(a[i]==mn) cmn++;
        }
        if(mn==mx) printf("%lld\n",1LL*n*(n-1));
        else printf("%lld\n",2LL*cmx*cmn);
    }
    return 0;
}