#include <iostream>
using namespace std;
int main()
{
    int n,a,i,b;
    cin>>n>>a;
    while(a%2==0)
        a/=2;
    while(a%3==0)
        a/=3;
    for(i=1;i<n;i++)
    {
        cin>>b;
        while(b%2==0)
            b/=2;
        while(b%3==0)
            b/=3;
        if(a!=b)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}