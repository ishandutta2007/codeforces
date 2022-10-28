#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,t;
    cin>>a;
    for(i=1;i<=16;i++)
    {
        t=a;
        t+=i;
        if(t<0)t*=-1;
        while(t!=0)
        {
            if(t%10==8)
            {
                cout<<i;
                return 0;
            }
            t/=10;
        }
    }
    return 0;
}