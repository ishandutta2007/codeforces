#include <iostream>
using namespace std;
int main()
{
    int n,i,a,b,s=0,sol=99999999;
    bool ok=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        s+=a;
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(s>=a and s<=b)
        {
            cout<<s;
            return 0;
        }
        if(a>s and a<sol)
        {
            sol=a;
            ok=1;
        }
    }
    if(ok)
        cout<<sol;
    else
        cout<<-1;
    return 0;
}