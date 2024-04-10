#include <iostream>

using namespace std;

int main()
{
    long long int n,k,x;
    cin>>n>>k;
    x=(n%2==0)?n/2:n/2+1;
    if(k<=x)
        cout<<2*k-1;
    else
        cout<<2*(k-x);
    return 0;
}