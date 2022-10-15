#include <iostream>
using namespace std;
int main()
{
    int last=0,i,n,k,a,s=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(a<8)
        {
            bool intr=0;
            if(a+last<=8)
            {
                s=s+a+last;
                last=0;
                intr=1;
            }
            if(!intr)
            {
            s+=8;
            last-=(8-a);
            }
        }
        else
        {
            s+=8;
            last+=a-8;
        }
        if(s>=k)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}