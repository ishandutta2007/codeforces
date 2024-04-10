#include <iostream>
using namespace std;
int n,k,best=1e9,a;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(k%a==0)
            best=min(best,k/a);
    }
    cout<<best;
    return 0;
}
/**
**/