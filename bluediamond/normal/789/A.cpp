#include <iostream>
using namespace std;
int main()
{
    int n,k,i,x,s=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x%k==0)
            s+=x/k;
        else
            s+=x/k+1;
    }
    if(s%2==0)
        cout<<s/2;
    else
        cout<<s/2+1;
    return 0;
}