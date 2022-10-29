#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=(int)1e9+7;
int qpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}

const int N=200005;
int C[N],a[N],n,k,pre[N];//C(i,k-1)
int CC[N];
char s[N];

signed main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'0';
    if(k==0) 
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum=(sum*10%MOD+a[i])%MOD;
        cout<<sum<<endl;
        return 0;
    }
    int ans=0;
    C[k-1]=1;
    for(int i=k;i<=n;i++) C[i]=C[i-1]*qpow(i-k+1,MOD-2)%MOD*i%MOD;
    CC[k]=1;
    for(int i=k+1;i<=n;i++) CC[i]=CC[i-1]*qpow(i-k,MOD-2)%MOD*i%MOD;
    for(int i=1;i<=n-k;i++) pre[i]=(pre[i-1]+C[n-i-1]*qpow(10,i-1)%MOD)%MOD;
    for(int i=1;i<n;i++)
    {
        int base=min(n-i,n-k);
        ans=(ans+pre[base]*a[i]%MOD)%MOD;
        if(i-1>=k) ans=(ans+CC[i-1]*qpow(10,n-i)%MOD*a[i]%MOD)%MOD;
    }
    int tmp=CC[n-1];
    cout<<(ans+tmp*a[n]%MOD)%MOD<<endl;
    return 0;
}