#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
inline int solve(long long n)
{
    long long x=2;
    while(!(n&1)) x<<=1,n>>=1;
    return n==1?-1:min(x,n);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%d\n",solve(n));
    }
    return 0;
}