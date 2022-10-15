#include <iostream>
#include <algorithm>
using namespace std;
int n,v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    if(v[1]==v[n/2] and v[n/2+1]==v[n] and v[1]!=v[n])
    {
        cout<<"YES\n";
        cout<<v[1]<<" "<<v[n];
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
/**
12
zACaAbbaazzC
123456789012
**/