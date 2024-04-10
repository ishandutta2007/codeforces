 #include<stdio.h>

int main()
{
    __int64 n, m, a, sum;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    sum = ((n+a-1)/a) * ((m+a-1)/a);
    printf("%I64d\n",sum);
    return 0;
}