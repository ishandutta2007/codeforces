#include <bits/stdc++.h>
using namespace std;
int n,a,ans=-10000000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        int rad=sqrt(a);
        if(rad*rad!=a)
            ans=max(ans,a);
    }
    cout<<ans;
    return 0;
}