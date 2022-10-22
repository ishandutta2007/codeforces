#include<bits/stdc++.h>
#define N 50
int T,n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==3)
        {
            puts("3 2 1");
            puts("1 3 2");
            puts("3 1 2");
            continue;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=1,now=i;j<=n;++j)
                now=(now+n-1)%n,printf("%d ",now+1);
            putchar('\n');
        }
    }
    return 0;
}