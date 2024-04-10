#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int p=998244353;
int a[1000003];
signed main()
{
    for(int T=read(); T--;)
    {
        int n=read(),A=0,B=0;
        for(int i=1,x; i<=n; i++) x=read(),A+=x,B^=x;
        A+=(1ll<<52),B^=(1ll<<52);
        int f=0;
        if(A&1) ++A,B^=(1ll<<52),B^=((1ll<<52)+1),f=1;
        B<<=1;
        assert((1ll<<52)>1000000000ll*100000ll);
        int X=B-A;
        puts("3");
        printf("%lld %lld %lld\n",(1ll<<52)+f,X/2,X/2);
    }
    return 0;
}