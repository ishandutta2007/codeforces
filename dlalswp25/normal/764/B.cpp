#include <stdio.h>

int main()
{
    int n, i;
    int a[200005];
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < n; i++)
    {
        if(n % 2)
        {
            if(i % 2)   printf("%d ", a[i]);
            else    printf("%d ", a[n - i - 1]);
        }
        else
        {
            if(i <= n - i - 1)
            {
                if(i % 2)   printf("%d ", a[i]);
                else    printf("%d ", a[n - i - 1]);
            }
            else
            {
                if(i % 2)   printf("%d ", a[n - i - 1]);
                else    printf("%d ", a[i]);
            }
        }
    }
    
    return 0;
}