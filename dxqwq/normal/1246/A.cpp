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
signed main()
{
    int N=read(),p=read();
    for(int i=1; i<=1000; i++)
    {
        int n=N;
        n-=i*p;
        if(n<i) continue;
        if(n<0)
        {
            puts("-1");
            return 0;
        }
        int ans=0;
        while(n)
        {
            ++ans,n-=n&(-n);
        }
        if(ans<=i)
        {
            printf("%lld\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}