#include <stdio.h>

int a[20000];
int q[20000];
int qi;
int c[20000];

int main()
{
    int i, j, n, m;
    scanf("%d%d", &n, &m);
    a[n]=1;
    q[qi++]=n;
    for(i=0;i<qi;i++)
    {
        if(q[i]*2 <= 10000 && a[q[i]*2] == 0)
        {
            a[q[i]*2]=a[q[i]]+1;
            q[qi++]=q[i]*2;
        }
        if(q[i]-1 >= 0 && a[q[i]-1] == 0)
        {
            a[q[i]-1]=a[q[i]]+1;
            q[qi++]=q[i]-1;
        }
    }
    printf("%d", a[m]-1);
    return 0;
}