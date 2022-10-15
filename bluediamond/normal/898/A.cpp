#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n%10<=5)
        cout<<n/10*10;
    else
        cout<<(n/10+1)*10;
    return 0;
}
/**

**/