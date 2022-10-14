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
        int n=read(),p=1000000000,q=0;
        for(int i=1; i<=n; i++) a[i]=read();
        bool f=0;
        for(int i=1; i<n; i++) if(abs(a[i]-a[i+1])>=2)
        {
            puts("Yes");
            printf("%lld %lld\n",i,i+1);
            f=1;
            break;
        }
        if(!f) puts("No");
    }
    return 0;
}