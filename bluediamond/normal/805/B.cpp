#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n;
    if(n==1)
    {
        cout<<"a";
        return 0;
    }
    cout<<"aa";
    a=b=0;
    for(int i=3;i<=n;i++)
    {
        if(a==0 and b==0)
            c=1;
        if(a==0 and b==1)
            c=1;
        if(a==1 and b==1)
            c=0;
        cout<<char{c+'a'};
        a=b;
        b=c;
    }
    return 0;
}