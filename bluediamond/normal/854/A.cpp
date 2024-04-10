#include <iostream>
using namespace std;
int f(int a,int b)
{
    if(b==0)
        return a;
    return f(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,ma=1,mb;
    cin>>n;
    mb=n-1;
    for(i=1;i<=n/2;i++)
        if(i*mb>ma*(n-i) and i<n-i and f(i,n-i)==1)
        {
            ma=i;
            mb=n-i;
        }
    cout<<ma<<" "<<mb;
    return 0;
}
/*
m1 > ma
m2   mb
m1*mb>ma*m2
*/