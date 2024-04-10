#include <bits/stdc++.h>
using namespace std;
long long x,y,a,b;
int main()
{
    cin>>y>>x;///x original , y copie
    if(x==0)
    {
        cout<<"No";
        return 0;
    }
    a=1;
    a+=x-1;
    b+=x-1;
    if(b==0)
    {
        if(y==0)
            cout<<"Yes";
        else
            cout<<"No";
        return 0;
    }
    if(y-b>=0 and (y-b)%2==0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
/**
**/