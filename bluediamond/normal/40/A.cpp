#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld x,y,dist;

bool Greater(int x)
{
    return ((ld)x>=dist);
}

bool eq(ld x,ld y)
{
    if(x>=0 && y>=0) return 1;
    if(x<=0 && y<=0) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    dist=sqrt(x*x+y*y);
    int r=0,pas=(1<<30);
    while(pas)
    {
        if(Greater(r+pas)==0)
            r+=pas;
        pas/=2;
    }
    r++;
    if((ld)r==dist)
    {
        cout<<"black\n";
        return 0;
    }
    if(eq(x,y))
    {
        if(r%2)
            cout<<"black\n";
        else
            cout<<"white\n";
    }
    else
    {
        if(r%2==0)
            cout<<"black\n";
        else
            cout<<"white\n";
    }
    return 0;
}