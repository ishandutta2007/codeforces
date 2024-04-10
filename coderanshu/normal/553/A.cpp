#include<iostream>
using namespace std;
#define ll long long

const int N=1000;
const int NC=10005,MOD=1000000007;

ll inv[NC],fac_inv[NC],fac[NC];
void initialize()
{
    ll i;
    inv[1]=1;
    for(i=2;i<=NC-2;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD; 
    fac[0]=fac[1]=1;
    for(i=2;i<=NC-2;i++)
        fac[i]=i*fac[i-1]%MOD;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=NC-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    return (fac[n]*fac_inv[r]%MOD)*fac_inv[n-r]%MOD;
}

int a[N];
ll dp[N];

int main()
{
    initialize();
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
        scanf("%d",a+i);
    dp[0]=1;
    int sum=a[0];
    for(int i=1;i<k;++i)
    {
        dp[i]=dp[i-1]*ncr(sum+a[i]-1,a[i]-1)%MOD;
        sum+=a[i];
    }
    printf("%lld",dp[k-1]);

}