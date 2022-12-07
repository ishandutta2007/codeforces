#include<bits/stdc++.h>
using namespace std;
int a[200005];
void work(){
    int n,g=0,i,x,mx=0;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    if(a[1]==a[n]){
        printf("%d\n",n>>1);
        return;
    }
    for(i=1;i<=n;++i){
        if(a[i]!=a[i+1]){
            ans=max(ans,1LL*i*(n-i));
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}