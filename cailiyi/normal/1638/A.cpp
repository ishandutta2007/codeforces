#include<bits/stdc++.h>
#define N 500
using namespace std;
int T,n,p[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",p+i);
        for(int i=1,j;i<=n;++i) if(p[i]!=i)
        {
            for(j=i+1;j<=n && p[j]!=i;++j);
            reverse(p+i,p+j+1);break;
        }
        for(int i=1;i<=n;++i) printf("%d ",p[i]);
        putchar('\n');
    }
    return 0;
}