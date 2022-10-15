#include <iostream>
using namespace std;
int v[105];
int main()
{
    int n,k,poz;
    cin>>n>>k;
    if(k>=2)
    {
        cout<<"YES";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(!v[i])
            poz=i;
    }
    cin>>v[poz];
    for(int i=1;i<=n;i++)
        if(v[i]<=v[i-1])
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}