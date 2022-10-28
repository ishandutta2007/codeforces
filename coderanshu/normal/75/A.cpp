#include<bits/stdc++.h>
using namespace std;
long int compute(long int n)
{
    long int r=0,z=1;
    while(n!=0)
    {
        if(n%10!=0)
        {
            r+=(n%10)*z;z*=10;
        }
        n/=10;
    }
    return r;
}
int main()
{
   long int a,b;
   cin>>a>>b;
   if(compute(a)+compute(b)==compute(a+b))
   cout<<"YES";
   else cout<<"NO";
    return 0;
}