#include <iostream>
using namespace std;
int main()
{
    long long n,m,a,x,y;
    cin>>n>>m>>a;
    x=n/a;
    y=m/a;
    if(n%a)
        x++;
    if(m%a)
        y++;
    cout<<x*y;
    return 0;
}