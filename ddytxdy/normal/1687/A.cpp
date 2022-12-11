#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e5+50;
int T,n,k,a[N];LL s[N];
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
    if(k<=n){
        LL ans=0;
        for(int i=k;i<=n;i++)
            ans=max(ans,s[i]-s[i-k]);
        printf("%lld\n",ans+1ll*k*(k-1)/2);
    }
    else{
        printf("%lld\n",s[n]+1ll*k*n-1ll*n*(n+1)/2);
    }
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
}