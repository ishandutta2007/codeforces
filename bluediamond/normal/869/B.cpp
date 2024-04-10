#include <iostream>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    if(b-a<=6)
    {
        long long uc=1;
        for(long long i=a+1;i<=b;i++)
            uc=(uc*(i%10))%10;
        cout<<uc;
        return 0;
    }
    cout<<0;
    return 0;
}