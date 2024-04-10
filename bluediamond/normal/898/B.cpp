#include <iostream>
using namespace std;
int main()
{
    long long n,a,b;
    cin>>n>>a>>b;
    for(long long i=0;i*a<=n;i++)///luam i de a
        if((n-i*a)%b==0)
        {
            cout<<"YES\n";
            cout<<i<<" "<<(n-i*a)/b;
            return 0;
        }
    cout<<"NO";
    return 0;
}
/**

**/