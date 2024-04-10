#include <iostream>
using namespace std;
int main()
{
    int n,k,i,p=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cout<<char{'a'+p};
        p++;
        if(p==k)
            p=0;
    }
    return 0;
}