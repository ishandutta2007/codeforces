#include <bits/stdc++.h>
using namespace std;
int n,k,x,v[105];
int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int nr=1;
    for(int i=n;nr<=k;i--)
    {
        v[i]=x;
        nr++;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=v[i];
    cout<<sum;
    return 0;
}