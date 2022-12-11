#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+50,mod=1e9+7,inf=1e9;
int T,n,p,a[N],b[N],ans;int j;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
void solve(){
    n=read();p=read();ans=j=0;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=n,now=a[n];i;i--){
        if(now!=a[i]){
            if(j&&p!=1)while(now!=a[i]&&abs(j)!=inf)j=min(max(1ll*j*p,-1ll*inf),1ll*inf),now--;
            else now=a[i];
        }
        if(j>0)j--,(ans-=power(p,a[i]))%=mod;
        else j++,(ans+=power(p,a[i]))%=mod;
    }
    if(j<0)ans=-ans;
    printf("%d\n",(ans+mod)%mod);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}