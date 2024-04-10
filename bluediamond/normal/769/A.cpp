#include <iostream>
using namespace std;
int main()
{
    int n,i,a,mi,ma;
    cin>>n>>a;
    mi=ma=a;
    for(i=1;i<n;i++)
    {
        cin>>a;
        if(a<mi)
            mi=a;
        if(a>ma)
            ma=a;
    }
    a=(mi+ma)/2;
    if((mi+ma)%2)
        a++;
    cout<<a;
    return 0;
}