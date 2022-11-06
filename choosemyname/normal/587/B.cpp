#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
long long dp[1000010];
int num[1000010];
pair<int,int> a[1000010];
long long c[1000010],c2[1000010];
const int mod=inf+7;
int ksm(int i,int j)
{
    long long k=1,l=i;
    while(j)
    {
        if(j&1)
            k=k*l%mod;
        l=l*l%mod;
        j=j>>1;
    }
    return k;
}
int main()
{
    long long n,l,k,n1,n2,n3;
    cin>>n>>l>>k;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d",&num[n1]);
        a[n1]=make_pair(num[n1],n1);
    }
    sort(a+1,a+n+1);
    for(n1=1;n1<=n;n1++)
        dp[n1]=1;
    for(n1=2;n1<=k;n1++)
    {
        long long now=0;
        for(n2=1;n2<=n;)
        {
            for(n3=n2;n3<=n&&a[n3].first==a[n2].first;n3++)
                now=(now+dp[n1*n-2*n+n3])%mod;
            for(n3=n2;n3<=n&&a[n3].first==a[n2].first;n3++)
                dp[n1*n-n+n3]=now;
        //  cout<<n2<<' '<<now<<endl;
            n2=n3;
        }
    }
    c[0]=1;
    for(n1=1;n1<=k;n1++)
        c[n1]=(c[n1-1]*((l/n-n1+1)%mod)%mod)*ksm(n1,mod-2)%mod;
    c2[0]=1;
    for(n1=1;n1<=k;n1++)
        c2[n1]=(c2[n1-1]*((l/n-n1+2)%mod))%mod*ksm(n1,mod-2)%mod;   
    long long ans=0;
    for(n1=1;n1<=n*k;n1++)
    {
        int nn=(n1-1)%n+1,kk=(n1-1)/n+1;
    //  cout<<n1<<' '<<nn<<' '<<kk<<' '<<l/n<<endl;
        if(a[nn].second<=(l%n))
        {
            if(kk<=l/n+1)
            {
        //      cout<<c2[kk]<<endl;
                ans=(ans+dp[n1]*((l/n+1-kk+1)%mod))%mod;
            }
        }
        else
            if(kk<=l/n)
            {
            //  cout<<c[kk]<<endl;
                ans=(ans+dp[n1]*((l/n+1-kk)%mod))%mod;
            }
    }
    cout<<ans;
            
}