#include <iostream>
using namespace std;
int main()
{
    double l,r,x,y,k,i;
    cin>>l>>r>>x>>y>>k;
    for(i=x;i<=y;i++)
        if(l<=k*i and k*i<=r)
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}