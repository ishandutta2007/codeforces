#include <iostream>
using namespace std;
int main()
{
    int n,b,d,x,i,s=0,sol=0;
    cin>>n>>b>>d;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x<=b)
            s+=x;
        if(s>d)
        {
            s=0;
            sol++;
        }
    }
    cout<<sol;
    return 0;
}