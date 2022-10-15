#include <iostream>
using namespace std;
int main()
{
    long long a,b,x;
    cin>>a>>b;
    x=a/b;
    if(x%2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}