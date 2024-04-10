#include<bits/stdc++.h>
#define N 50
using namespace std;
int T,n,m;
char a[N+5],b[N+5];
inline bool check()
{
    for(int i=m-1;i;--i)
        if(b[m-i]!=a[n-i]) return 0;
    for(int i=0;i<=n-m;++i)
        if(a[i]==b[0]) return 1;
    return 0;
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m);
        scanf("%s %s",a,b);
        puts(check()?"YES":"NO");
    }
    return 0;
}