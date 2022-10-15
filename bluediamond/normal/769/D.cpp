#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int X=10000+5;

int f[X];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        f[x]++;
    }
    if(k==0)
    {
        ll ans=0LL;
        for(int i=0;i<X;i++)
            ans+=f[i]*(long long)(f[i]-1LL)/2;
        cout<<ans<<"\n";
        return 0;
    }
    ll ans=0LL;
    for(int i=0;i<X;i++)
        for(int j=i+1;j<X;j++)
        {
            int xr=(i^j);
            int bt=__builtin_popcount(xr);
            if(bt==k)
                ans+=f[i]*(long long)f[j];
        }
    cout<<ans<<"\n";
    return 0;
}