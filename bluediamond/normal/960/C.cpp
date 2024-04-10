#include <bits/stdc++.h>
using namespace std;
long long x,d;
const int N=10000;
long long n,v[N+5];
int main()
{
    cin>>x>>d;
    if(x==1)
    {
        cout<<"1\n";
        cout<<"1";
        return 0;
    }
    if(x==2)
    {
        cout<<"2\n";
        cout<<"1 1";
        return 0;
    }
    long long i;
    for(i=60;i>=1;i--)
    {
        long long val=(1LL<<i)-1;
        while(val<=x)
        {
            x-=val;
            long long start=v[n]+d+1;
            for(int j=1;j<=i;j++)
            {
                v[++n]=start;
            }
        }
    }
    if(x!=0)
    {
        cout<<-1;
        return 0;
    }
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
/**
746 173




**/