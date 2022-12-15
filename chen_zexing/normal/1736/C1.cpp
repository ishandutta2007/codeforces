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
        long long ans=0;
        for(int i=1,r=1;i<=n;i++){
            while(r<n&&a[r+1]-1>=r-i+1) r++;
            ans+=r-i+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}