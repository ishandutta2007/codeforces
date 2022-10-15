#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,k,p2=0,p5=0;
    cin>>n>>k;
    while(n%2==0 and p2<k)
    {
        n/=2;
        p2++;
    }
    while(n%5==0 and p5<k)
    {
        n/=5;
        p5++;
    }
    if(p2>k)k=p2;
    if(p5>k)k=p5;
    cout<<n;
    for(long long i=1;i<=k;i++)
        cout<<0;
    return 0;
}