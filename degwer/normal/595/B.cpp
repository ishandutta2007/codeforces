#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int main()
{
    int num,dig;
    scanf("%d%d",&num,&dig);
    vector<int>a,b;
    for(int i=0;i<num/dig;i++)
    {
        int z;
        scanf("%d",&z);
        a.push_back(z);
    }
    for(int i=0;i<num/dig;i++)
    {
        int z;
        scanf("%d",&z);
        b.push_back(z);
    }
    int t=1;
    for(int i=0;i<dig-1;i++)t*=10;
    ll ret=1;
    for(int i=0;i<num/dig;i++)
    {
        ll r=0;
        for(int j=0;j<10;j++)
        {
            if(j!=b[i])
            {
                r+=(t*(j+1)+a[i]-1)/a[i];
                r-=(t*j+a[i]-1)/a[i];
            }
        }
        ret*=r;
        ret%=mod;
    }
    printf("%I64d\n",ret);
}