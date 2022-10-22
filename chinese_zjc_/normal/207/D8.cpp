#include<cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", 2 - !((n / 1000) & 1));
    return 0;
}