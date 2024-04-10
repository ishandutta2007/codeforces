#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,a,ma=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>ma)
            ma=a;
    }
    if(ma>25)
        cout<<ma-25;
    else
        cout<<0;
    return 0;
}