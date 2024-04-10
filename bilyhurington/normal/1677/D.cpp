#include<bits/stdc++.h>
using namespace std;
int T,n,k,p[1000010];
const int mod=998244353;
void solve(){
    scanf("%d %d",&n,&k);k++;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    if(p[1]>0){puts("0");return;}
    else p[1]=0;
    for(int i=n-k+2;i<=n;i++){
        if(p[i]!=-1&&p[i]!=0){
            puts("0");
            return;
        }
    }
    long long ans=1;
    for(int i=1;i<=n-k+1;i++){
        if(!p[i]) ans=ans*k%mod;
        if(p[i]==-1) ans=ans*(k+i-1)%mod;
    }
    // if(p[n-k+1]==-1) ans=ans*(n-k+1)%mod;
    for(int i=1;i<k;i++) ans=ans*i%mod;
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}