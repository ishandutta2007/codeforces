#include <iostream>
using namespace std;
int n,poz,st,dr,cost=0;
int main()
{
    cin>>n>>poz>>st>>dr;
    if(poz<st)
    {
        while(poz!=st)
        {
            poz++;
            cost++;
        }
    }
    if(dr<poz)
    {
        while(dr!=poz)
        {
            poz--;
            cost++;
        }
    }
    if(st!=1 and dr!=n)
    {
        int d1=poz-st,d2=dr-poz;
        cout<<2*min(d1,d2)+max(d1,d2)+2+cost;
        return 0;
    }
    if(st==1)
    {
        if(dr==n)
            cout<<0+cost;
        else
            cout<<dr-poz+1+cost;
        return 0;
    }
    cout<<poz-st+1+cost;
    return 0;
}
/**
**/