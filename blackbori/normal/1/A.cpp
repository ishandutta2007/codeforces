#include <cstdio>

int main()
{
    long long int n, m, a;

    scanf("%lld %lld %lld",&n,&m,&a);

    printf("%lld\n",((n-1)/a+1) * ((m-1)/a+1));

    return 0;
}