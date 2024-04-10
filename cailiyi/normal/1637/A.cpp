#include<bits/stdc++.h>
#define N 10000
using namespace std;
int T,n,a[N+5],b[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),b[i]=a[i];
        sort(b+1,b+1+n);
        bool flag=0;
        for(int i=1;i<=n;++i)
            if(a[i]!=b[i]) {flag=1;break;}
        flag?puts("YES"):puts("NO");
    }
    return 0;
}