#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n < 999) cout<<n+2;
    else
    {
        if (n == 999)cout<<1;
        if (n == 1000) cout<<2;
    }
    return 0;
}