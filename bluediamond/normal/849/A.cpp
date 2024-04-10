#include <iostream>
#include <algorithm>
using namespace std;
int v[105];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    if(n%2==1)
    {
        if(v[1]%2==1 and v[n]%2==1)
            cout<<"Yes";
        else
            cout<<"No";
        return 0;
    }
    else
        cout<<"No";
    return 0;
}