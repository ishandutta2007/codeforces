#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        int l=n,r=n*2000;
        while(l<r){
            int mid=(l+r)/2;
            if(query(mid)==1) r=mid;
            else l=mid+1;
        }
        int ans=l;
        for(int i=2;i<=n;i++){
            int temp=query(l/i);
            if(temp) ans=min(ans,temp*(l/i));
        }
        printf("! %d\n",ans);
    }
    return 0;
}