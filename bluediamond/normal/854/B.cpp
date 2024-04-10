#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,k,x;
    cin>>n>>k;
    if(n==k or k==0)
    {
        cout<<"0 0";
        return 0;
    }
    cout<<"1 ";
    if(n%3==0)
    {
        x=n/3;
        if(k<x)
        {
            cout<<2*k;
            return 0;
        }
        cout<<n-k;
        return 0;
    }
    if(n%3==1)
    {
        x=n/3;
        if(k<=x)
        {
            cout<<2*k;
            return 0;
        }
        cout<<2*x-(k-(x+1));
    }
    if(n%3==2)
    {
        x=n/3+1;
        if(k<x)
        {
            cout<<2*k;
            return 0;
        }
        cout<<n-k;
    }
    return 0;
}
///10 9
/*
1 2 3 4 5 6 7 8 9 10 11
  *     *     *      *
  */