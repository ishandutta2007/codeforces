#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL read()
{
    LL ans=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return ans*f;
}

const LL N=1e5+5;
LL n,a[N],b[N],ans;

int main()
{
    n=read();
    for(LL i=1;i<=n;++i)
        a[i]=read();
    for(LL i=n;i>=1;--i)
    //  gcd
        b[i]=__gcd(b[i+1],a[i]);
    for(LL i=1;i<=n;++i)
    //  gcd { ai , aj | i < j }
        ans=__gcd(ans,a[i]*b[i+1]);
    //  gcd { ai , aj | i < j } / gcd ( a1 , a2 ... an )
    printf("%lld\n",ans/b[1]);
    return 0;
}