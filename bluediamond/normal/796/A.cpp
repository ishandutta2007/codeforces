#include <iostream>
using namespace std;
int main()
{
    int n,m,k,i,a,be=9999999;
    cin>>n>>m>>k;
    for(i=1;i<m;i++)
    {
        cin>>a;
        if(k>=a and a)
            be=m-i;
    }
    cin>>a;
    for(i=m+1;i<=n;i++)
    {
        cin>>a;
        if(i-m<be and k>=a and a)
            be=i-m;
    }
    cout<<be<<0;
    return 0;
}