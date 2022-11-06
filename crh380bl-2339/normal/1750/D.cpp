#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[200005];
int prime[200005],cnt=0;
int mu[200005],val[200005];
void work(){
    int n,m,i,j,ans=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    //m = (m/a[1])*a[1];
    cnt=0;
    int tmp=a[1];
    for(i=2;i*i<=tmp;++i){
        if(tmp%i==0){
            prime[cnt++] = i;
            while(tmp%i==0)tmp/=i;
        }
    }
    if(tmp>1)prime[cnt++] = tmp;
    //for(i=0;i<cnt;++i)printf("%d ",prime[i]);
    for(i=2;i<=n;++i)if(a[i-1]%a[i]){
        puts("0");
        return;
    }
    mu[0]=1;val[0]=1;
    for(int S=1;S<(1<<cnt);++S){
        if(S&1)mu[S]=-mu[S>>1];
        else mu[S]=mu[S>>1];
        val[S]=1;
        for(j=0;j<cnt;++j){
            if((S>>j)&1)val[S]*=prime[j];
        }
    }
    for(i=2;i<=n;++i){
        int S1=0;
        int d = (a[i-1]/a[i]);
        for(j=0;j<cnt;++j)if(d%prime[j] == 0){
            S1|=(1<<j);
        }
        int m1 = m/a[i];
        int t=0;
        for(int S=0;S<(1<<cnt);++S){
            if((S|S1)!=S1)continue;
            t = (t + mu[S] * (m1/val[S]));
            t%=mod;
        } 
        t=(t+mod)%mod;
        ans=1LL*t*ans%mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)work();
    return 0;
}