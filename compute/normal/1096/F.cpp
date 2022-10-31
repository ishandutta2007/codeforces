#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
const int mod=998244353;
int arr[maxn];
int sum[maxn];
int lef[maxn];
long long quick(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
long long inv(long long a)
{
    return quick(a,mod-2);
}
void add(int x)
{
    while(x<maxn)
    {
        sum[x]++;
        x+=x&-x;
    }
}
int query(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=sum[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    memset(sum,0,sizeof(sum));
    memset(lef,0,sizeof(lef));
    int n;
    scanf("%d",&n);
    long long ans=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]==-1) cnt++;
        else{
            add(arr[i]);
            ans=(ans+query(n)-query(arr[i]))%mod;
        }
    }
    ans=(ans+1LL*cnt*(cnt-1)%mod*inv(2)%mod*inv(2)%mod)%mod;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1) cur++;
        else {
            lef[i]=(n-arr[i])-(query(n)-query(arr[i]));
            ans=(ans+1LL*lef[i]*cur%mod*inv(cnt)%mod)%mod;
            ans=(ans+1LL*(cnt-lef[i])*(cnt-cur)%mod*inv(cnt)%mod)%mod;
        }
    }
    printf("%lld\n",ans);


}