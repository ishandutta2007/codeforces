#include <iostream>
using namespace std;
int main()
{
    long long a,b,x,p=1,i;
    cin>>a>>b;
    if(a<b)
        x=a;
    else
        x=b;
    for(i=1;i<=x;i++)
        p*=i;
    cout<<p;
    return 0;
}