#include <iostream>
using namespace std;
const int nmax=500000;
long long n,sum[nmax+5],ap[nmax+5],j,cnt,ans,a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    if(sum[n]%3!=0)
    {
        cout<<0;
        return 0;
    }
    a=sum[n]/3;
    for(int i=n-1;i>=1;i--)
    {
        ap[i]=ap[i+1];
        if(sum[i]==2*a)ap[i]++;
    }
    for(int i=1;i<=n;i++)
        if(sum[i]==a)
            ans+=ap[i+1];
    cout<<ans;
    return 0;
}
/**

**/