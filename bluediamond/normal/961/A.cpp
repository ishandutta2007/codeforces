#include <bits/stdc++.h>
using namespace std;
int n,m;
int ap[1005];
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int a;
        cin>>a;
        ap[a]++;
    }
    int ans=ap[1];
    for(int i=2;i<=n;i++)
        ans=min(ans,ap[i]);
    cout<<ans;
    return 0;
}
/**
**/