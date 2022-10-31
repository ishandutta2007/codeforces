#include <stdio.h>
int a[100001];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    for (int w=1;w<=n;++w)
        if (n%w==0)
        {
            bool f=true;
            for (int j=0;f&&j<n/w;++j)
            {
                if (j&&a[j*w+1]==a[j*w-w+1])
                    f=false;
                for (int k=1;f&&k<=w;++k)
                    if (a[j*w+k]!=a[j*w+1])
                        f=false;
            }
            if (f)
            {
                printf("YES\n");
                return 0;
            }
        }
    printf("NO\n");
    return 0;
}