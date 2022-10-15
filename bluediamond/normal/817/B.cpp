#include <iostream>
#include <algorithm>
using namespace std;
int v[100005];
int main()
{
    int n,x,y,z;
    long long i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    x=v[1];
    y=v[2];
    z=v[3];
    if(x<y and y<z)
    {
        for(i=3;i<=n;i++)
            if(v[i+1]!=z)
                break;
        cout<<i-2;
        return 0;
    }
    if(x==y and y==z)
    {
        for(i=1;i<=n;i++)
            if(v[i+1]!=z)
                break;
        cout<<i*(i-1)*(i-2)/6;
    }
    if(x==y and y<z)
    {
        for(i=2;i<=n;i++)
            if(v[i+1]!=z)
                break;
        cout<<i-2;
    }
    if(x<y and y==z)
    {
        for(i=1;i<=n;i++)
            if(v[i+1]!=z)
                break;
        i--;
        cout<<(i)*(i-1)/2;
    }
    if(x<y and y<z)
    {
        for(i=2;i<=n;i++)
            if(v[i]!=z)
                break;
        i-=2;
        cout<<i;
    }
    return 0;
}
/*
1 2 3 3 3
*/