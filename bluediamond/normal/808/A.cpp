#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,x,p=1,i;
    cin>>n;
    x=log10(n);
    for(i=1;i<=x;i++)
        p*=10;
    p*=(n/p+1);
    cout<<p-n;
    return 0;
}