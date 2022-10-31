#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long l,r;
    cin>>l>>r;
    puts("YES");
    for(long long i=0;i<(r-l+1);i+=2)
    {
        printf("%lld %lld\n",l+i,l+i+1);
    }
    return 0;
}