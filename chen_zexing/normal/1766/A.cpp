#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,ans=0,now=1;
        scanf("%d",&n);
        while(now<=n) ans+=min(9,n/now),now*=10;
        printf("%d\n",ans);
    }
    return 0;
}