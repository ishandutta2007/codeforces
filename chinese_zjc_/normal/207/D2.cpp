#include<cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    n -= 8500;
    n /= 500;
    if(n < 0) n = -n;
    n = (4 - n / 2) % 3 + 1;
    printf("%d", n);
    return 0;
}