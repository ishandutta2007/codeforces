#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i;
    cin>>a>>b;
    i=(a+b)/2;
    if((a+b)%2)
    {
        if(i>=a)
        cout<<i<<" "<<0<<" "<<6-i;
        else cout<<6-i<<" "<<0<<" "<<i;
    }
    else 
    {
        if(i>a)
        cout<<i-1<<" "<<1<<" "<<6-i;
        else if(i==a)
        cout<<0<<" "<<6<<" "<<0;
        else 
        cout<<6-i<<" "<<1<<" "<<i-1;
    }
    return 0; 
}