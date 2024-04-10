#include<bits/stdc++.h>
using namespace std;
// nice concept of 2d array

int main()
{
    ios_base::sync_with_stdio(0);
    long int p,x,i,count=0,f,t;
    cin>>p;
    for(x=1;x<p;x++)
    {
        f=0;
        t=x;
        for(i=1;i<p-1;i++)
        {
            if(t%p-1==0)
            {
                f=1;break;
            }
            t=(t*x)%p;
        }
        if(f==0 && (t-1)%p==0)
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}