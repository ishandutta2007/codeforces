#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,a[N+5];
inline bool check()
{
    sort(a+1,a+1+n);
    for(int i=1;i<n;++i)
        if(a[i]+1==a[i+1]) return 1;
    return 0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);bool flag1=0;
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),flag1|=a[i]==1;
        puts(flag1 && check()?"NO":"YES");
    }
    return 0;
}