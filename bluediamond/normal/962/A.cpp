#include <iostream>

using namespace std;

const int N=200000;
int n,v[N+5];
long long S=0,cur=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        S+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cur+=v[i];
        if(2*cur>=S)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
/**
**/