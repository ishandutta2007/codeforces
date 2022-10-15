#include <bits/stdc++.h>

using namespace std;

int a,b,p=1,x=1,y=1,cost;

int main()
{
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    while(a<b)
    {
        if(p%2==1)
        {
            cost+=x;
            x++;
            a++;
        }
        else
        {
            cost+=y;
            y++;
            b--;
        }
        p++;
    }
    cout<<cost;
    return 0;
}
/**


**/