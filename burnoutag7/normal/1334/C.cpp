#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T,n;
ll a[300005];
ll b[300005];

int main(){

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",a+i,b+i);
        }
        a[n]=a[0];
        b[n]=b[0];
        ll cost=0;
        for(int i=0;i<n;i++){
            cost+=max(a[i+1]-b[i],0ll);
        }
        ll ans=1e18;
        for(int i=0;i<n;i++){
            ans=min(ans,cost+min(a[i+1],b[i]));
        }
        printf("%lld\n",ans);
    }

    return 0;
}