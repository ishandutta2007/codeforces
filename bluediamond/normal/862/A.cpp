#include <iostream>
using namespace std;
int ap[105];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,x,a,s=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        ap[a]=1;
    }
    for(int i=0;i<x;i++)
        if(ap[i]==0)
            s++;
    s+=ap[x];
    cout<<s;
    return 0;
}