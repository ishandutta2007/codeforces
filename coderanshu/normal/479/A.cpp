#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    d=max(a*b*c,a+b+c);
    if(a>=c)
    {
        cout<<max(d,a*(b+c));
    }
    else 
    {
        cout<<max(d,(a+b)*c);
    }
    return 0; 
}