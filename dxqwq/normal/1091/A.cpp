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
    int a=read(),b=read(),c=read();
    int x=min(a,min(b-1,c-2));
    printf("%lld\n",3*x+3);
    return 0;
}