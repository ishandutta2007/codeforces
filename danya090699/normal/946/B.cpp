#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int a, b;
    cin>>a>>b;
    while(a!=0 and b!=0)
    {
        if(a>=2*b) a%=(2*b);
        else if(b>=2*a) b%=(2*a);
        else break;
    }
    cout<<a<<" "<<b;
}