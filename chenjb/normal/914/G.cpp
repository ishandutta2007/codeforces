#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define inf 1000000007
#define inv 500000004
long long fib[200000];
long long ab[200000],c[200000],de[200000];
int n;
int pow17;
void FWT(long long *a,int n,int type)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                long long x=a[i+j],y=a[i+j+d];
                if(type==0)
                {
                    a[i+j]=(x+y)%inf;
                    a[i+j+d]=(x-y+inf)%inf;
                }
                else a[i+j]=(x+y)%inf;
            }
}
void UFWT(long long *a,int n,int type)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                long long x=a[i+j],y=a[i+j+d];
                if(type==0)
                {
                    a[i+j]=(x+y)*inv%inf;
                    a[i+j+d]=(x-y+inf)*inv%inf;
                }
                else a[i+j]=(x-y+inf)%inf;
            }
}
int main()
{
    pow17=1;
    for(int i=1;i<=17;i++)pow17*=2;

    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=pow17;i++)fib[i]=(fib[i-2]+fib[i-1])%inf;

    //init & get c
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        c[x]++;
    }

    //enumerate subset to get ab
    for(int i=0;i<pow17;i++)
    {
        for(int j=i;;j=(j-1)&i)
        {
            ab[i]=(ab[i]+c[j]*c[i^j])%inf;
            if (j==0)break;
        }
    }

    //get de
    for(int i=0;i<pow17;i++)de[i]=c[i];
    FWT(de,pow17,0);
    for(int i=0;i<pow17;i++)de[i]=de[i]*de[i]%inf;
    UFWT(de,pow17,0);
    
    //fib[i]
    for(int i=0;i<pow17;i++)
    {
        ab[i]=ab[i]*fib[i]%inf;
        c[i]=c[i]*fib[i]%inf;
        de[i]=de[i]*fib[i]%inf;
    }
    FWT(ab,pow17,1);
    FWT(c,pow17,1);
    FWT(de,pow17,1);
    for(int i=0;i<pow17;i++)ab[i]=ab[i]*c[i]%inf*de[i]%inf;
    UFWT(ab,pow17,1);

    //calculate the answer
    long long ans=0;
    for(int i=0;i<17;i++)ans=(ans+ab[1<<i])%inf;
    cout<<ans<<endl;
}