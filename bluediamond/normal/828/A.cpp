#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,a,b,b2=0,i,x,sum=0;
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)
        {
            if(a>0)
            {
                a--;
                continue;
            }
            if(b>0)
            {
                b--;
                b2++;
                continue;
            }
            if(b2>0)
            {
                b2--;
                continue;
            }
            sum++;
            continue;
        }
        if(b>0)
        {
            b--;
            continue;
        }
        sum+=2;
    }
    cout<<sum;
    return 0;
}
/*
6 1 3
2 2 1 1 2 2
*/