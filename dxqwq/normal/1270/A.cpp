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

signed main()
{
    for(int T=read(); T--;)
    {
        int n=read(),x=read(),y=read(),p=0,q=0;
        while(x--) p=max(p,read());
        while(y--) q=max(q,read());
        if(p>q) puts("Yes");
         else puts("No");
    }
    return 0;
}