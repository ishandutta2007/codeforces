#include <cstdio>
int a[1000];
void f(int x)
{
    if(x==0) return;
    int t = a[x];
    a[x] = a[x-1];
    a[x-1] = t;
    f(x-1);
}
int main()
{
    int x;
    scanf("%d", &x);
    for(int k = 0; k < x; k++)
        a[k] = k+1;
    f(x-1);
    for(int k = 0; k < x; k++)
        printf("%d ",a[k]);
    putchar('\n');
    return 0;
}