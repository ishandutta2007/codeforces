#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==3&&a[2]%2==1){puts("-1");return;}
    bool pd0=1,pd1=1;
    for(int i=2;i<n;i++){
        if(a[i]) pd0=0;
        if(a[i]>1) pd1=0;
    }
    if(pd0){puts("0");return;}
    if(pd1){puts("-1");return;}
    long long ans=0;
    for(int i=2;i<n;i++) ans+=(a[i]+1)/2;
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}