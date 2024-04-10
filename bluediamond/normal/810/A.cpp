#include <iostream>
using namespace std;
int f(double n,double s)
{
    double x=s/n;
    int y=x;
    if(x-y>=0.5)
        return y+1;
    return y;
}
int main()
{
    double n,s=0,k,i,a;
    int sum=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        s+=a;
    }
    if(f(n,s)==k)
        {
            cout<<0;
            return 0;
        }
    while(1)
    {
        sum++;
        s+=k;
        n++;
        if(f(n,s)==k)
        {
            cout<<sum;
            return 0;
        }
    }
    return 0;
}