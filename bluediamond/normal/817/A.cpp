#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x1,x2,y1,y2,a,b,i;
    cin>>x1>>y1>>x2>>y2>>a>>b;
    if(abs(x1-x2)%a!=0 or abs(y1-y2)%b!=0)
    {
        cout<<"NO";
        return 0;
    }
    while(x1<x2)
    {
        x1+=a;
        if(y1<y2)
        {
            y1+=b;
            continue;
        }
        y1-=b;
    }
    while(x1>x2)
    {
        x1-=a;
        if(y1<y2)
        {
            y1+=b;
            continue;
        }
        y1-=b;
    }
    if((abs(y1-y2)/b)%2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
/*
1 1 3 6
1 5


1 1
2 6
3 1

*/