#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[200010];
void solve(){
    scanf("%d %d",&n,&k);
    long long sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];a[i]-=(n-i);
    }
    sort(a+1,a+n+1);
    for(int i=n-k+1;i<=n;i++) sum-=a[i];
    printf("%lld\n",sum-1ll*k*(k-1)/2); 
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}