#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,s=0,loc=1;
    cin>>n>>a>>b>>c;
    for(int i=1;i<n;i++)
    {
        if(loc==1)
        {
            if(a<b)
            {
                s+=a;
                loc=2;
                continue;
            }
            s+=b;
            loc=3;
            continue;
        }
        if(loc==2)
        {
            if(a<c)
            {
                s+=a;
                loc=1;
                continue;
            }
            s+=c;
            loc=3;
            continue;
        }
        if(loc==3)
        {
            if(b<c)
            {
                s+=b;
                loc=1;
                continue;
            }
            s+=c;
            loc=2;
            continue;
        }
    }
    cout<<s;
    return 0;
}