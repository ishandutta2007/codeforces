#include<bits/stdc++.h>
using namespace std;
int T,n,a[5010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    long long ans=1e18;
    for(int i=1;i<=n;i++){
        long long x=0,sum=0;
        for(int j=i-1;j>=1;j--){
            x--;long long t=floor(1.0L*x/a[j]);
            x=t*a[j];sum-=t;
        }x=0;
        for(int j=i+1;j<=n;j++){
            x++;long long t=ceil(1.0L*x/a[j]);
            x=t*a[j];sum+=t;
        }
        ans=min(ans,sum);
        // printf("%lld\n",sum);
    }
    printf("%lld\n",ans);
}
int main(){
    T=1;
    while(T--) solve();
    return 0;
}