#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,h,m;
        cin>>n>>h>>m;
        int t=h*60+m,ans=INT_MAX;
        for(int i=1,x,y;i<=n;i++){
            scanf("%d%d",&x,&y);
            int tm=x*60+y;
            if(tm<t) tm+=1440;
            ans=min(ans,tm-t);
        }
        printf("%d %d\n",ans/60,ans%60);
    }
    return 0;
}