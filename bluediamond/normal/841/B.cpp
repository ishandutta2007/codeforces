#include <iostream>
using namespace std;
long long n,x,s,ok=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s+=x;
        if(x%2==1)
            ok=1;
    }
    if(s==1 or ok==1)
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}