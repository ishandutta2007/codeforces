#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while(b!=0)
    {
        a%=b;
        swap(a, b);
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    for(int a=n/2; a>=0; a--)
    {
        if(gcd(a, n-a)==1)
        {
            cout<<a<<" "<<n-a;
            break;
        }
    }
}