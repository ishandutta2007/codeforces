#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==1||n==2)
        {
            puts("No");
            continue;
        }
        puts("Yes");
        if(n%2==0)
        {
            printf("%d",2);
            printf(" %d %d\n",n/2,n/2+1);
            printf("%d",n-2);
            for(int i=1;i<=n;i++)
            {
                if(i!=n/2&&i!=n/2+1)
                    printf(" %d",i);
            }
            printf("\n");
        }
        else{
            printf("%d",1);
            printf(" %d\n",n/2+1);
            printf("%d",n-1);
            for(int i=1;i<=n;i++)
            {
                if(i!=n/2+1)
                    printf(" %d",i);
            }
            printf("\n");
        }
    }
    return 0;
}