#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,k,a[N+5];
inline bool check()
{
    for(int i=2,j=1;i<=n;++i)
    {
        while(a[i]-a[j]>k) ++j;
        if(a[i]-a[j]==k) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        sort(a+1,a+1+n);
        puts(check()?"YES":"NO");
    }
    return 0;
}