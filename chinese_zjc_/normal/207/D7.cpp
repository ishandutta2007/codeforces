#include<cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    n -= 33500;
    puts(n > 0 ? "3" : "2");
    return 0;
}